#include "../Video/timeline.h"
#include "../Actions/cut.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

Timeline timeline;

void resetTimeline() {
    timeline = Timeline();

    timeline.addVideo(
        Video("main", "video.mp4", 300.0)
    );

    timeline.addAudio(
        AudioData("main-audio", "audio.wav", 300.0)
    );
}

double getDuration() {
    if (!timeline.getVideos().empty()) {
        return timeline.getVideos()[0].getDuration();
    }

    return 0.0;
}

std::string response(
    const std::string& body,
    const std::string& status = "200 OK"
) {
    std::ostringstream out;

    out << "HTTP/1.1 " << status << "\r\n";
    out << "Content-Type: application/json\r\n";
    out << "Access-Control-Allow-Origin: *\r\n";
    out << "Access-Control-Allow-Headers: Content-Type\r\n";
    out << "Access-Control-Allow-Methods: POST, OPTIONS\r\n";
    out << "Content-Length: " << body.size() << "\r\n";
    out << "Connection: close\r\n";
    out << "\r\n";
    out << body;

    return out.str();
}

double extractNumber(
    const std::string& body,
    const std::string& key
) {
    std::string search = "\"" + key + "\":";

    size_t position = body.find(search);

    if (position == std::string::npos) {
        throw std::invalid_argument("Missing field: " + key);
    }

    position += search.size();

    return std::stod(body.substr(position));
}

void handleRequest(int client) {
    char buffer[8192];

    int bytes = read(client, buffer, sizeof(buffer) - 1);

    if (bytes <= 0) {
        close(client);
        return;
    }

    buffer[bytes] = '\0';

    std::string request(buffer);

    if (request.rfind("OPTIONS", 0) == 0) {
        std::string result = response("{}");
        write(client, result.c_str(), result.size());
        close(client);
        return;
    }

    size_t headerEnd = request.find("\r\n\r\n");

    std::string body;

    if (headerEnd != std::string::npos) {
        body = request.substr(headerEnd + 4);
    }

    try {
        if (request.rfind("POST /clear", 0) == 0) {
            resetTimeline();

            std::ostringstream json;
            json << "{\"success\":true,\"duration\":"
                 << getDuration()
                 << "}";

            std::string result = response(json.str());

            write(client, result.c_str(), result.size());
            close(client);
            return;
        }

        if (request.rfind("POST /cut", 0) == 0) {
            double start = extractNumber(body, "start");
            double end = extractNumber(body, "end");

            double duration = getDuration();

            /*
             * Backend validation.
             *
             * The browser is not trusted to decide whether
             * an operation is valid.
             */

            if (start < 0.0) {
                throw std::invalid_argument(
                    "Start time cannot be negative"
                );
            }

            if (end <= start) {
                throw std::invalid_argument(
                    "End time must be greater than start time"
                );
            }

            if (end > duration) {
                throw std::invalid_argument(
                    "End time cannot exceed timeline duration"
                );
            }

            CutAction cut(start, end);

            cut.execute(timeline);

            double newDuration = getDuration();

            std::ostringstream json;

            json << "{\"success\":true,"
                 << "\"start\":" << start << ","
                 << "\"end\":" << end << ","
                 << "\"duration\":" << newDuration
                 << "}";

            std::string result = response(json.str());

            write(client, result.c_str(), result.size());
            close(client);
            return;
        }

        std::string result = response(
            "{\"success\":false,\"error\":\"Unknown endpoint\"}",
            "404 Not Found"
        );

        write(client, result.c_str(), result.size());
        close(client);
    }
    catch (const std::exception& error) {
        std::string body =
            std::string("{\"success\":false,\"error\":\"") +
            error.what() +
            "\"}";

        std::string result = response(
            body,
            "400 Bad Request"
        );

        write(client, result.c_str(), result.size());
        close(client);
    }
}

int main() {
    resetTimeline();

    int server = socket(
        AF_INET,
        SOCK_STREAM,
        0
    );

    if (server < 0) {
        std::cerr << "Could not create socket.\n";
        return 1;
    }

    int reuse = 1;

    setsockopt(
        server,
        SOL_SOCKET,
        SO_REUSEADDR,
        &reuse,
        sizeof(reuse)
    );

    sockaddr_in address{};

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(8080);

    if (bind(
        server,
        reinterpret_cast<sockaddr*>(&address),
        sizeof(address)
    ) < 0) {
        std::cerr << "Could not bind port 8080.\n";
        close(server);
        return 1;
    }

    if (listen(server, 10) < 0) {
        std::cerr << "Could not listen.\n";
        close(server);
        return 1;
    }

    std::cout << "Proof backend running on http://127.0.0.1:8080\n";

    while (true) {
        int client = accept(
            server,
            nullptr,
            nullptr
        );

        if (client >= 0) {
            handleRequest(client);
        }
    }

    close(server);

    return 0;
}

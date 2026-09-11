#ifndef MEDIA_RESOURCE_H
#define MEDIA_RESOURCE_H

#include <string>
#include <stdexcept>
#include <algorithm>
#include <cctype>

class MediaResource {
private:
    std::string identity;
    std::string sourcePath;
    double duration;

    static bool isValidString(const std::string& str) {
        return !str.empty() && std::any_of(str.begin(), str.end(), [](unsigned char c) {
            return !std::isspace(c);
        });
    }

    void validate() const {
        if (!isValidString(identity)) {
            throw std::invalid_argument("MediaResource identity must be non-empty and contain non-whitespace characters");
        }
        if (!isValidString(sourcePath)) {
            throw std::invalid_argument("MediaResource source path must be non-empty and contain non-whitespace characters");
        }
        if (duration <= 0.0) {
            throw std::invalid_argument("MediaResource duration must be positive");
        }
    }

public:
    MediaResource(const std::string& identity,
                  const std::string& sourcePath,
                  double duration)
        : identity(identity), sourcePath(sourcePath), duration(duration) {
        validate();
    }

    const std::string& getIdentity() const { return identity; }
    const std::string& getSourcePath() const { return sourcePath; }
    double getDuration() const { return duration; }

    void setDuration(double newDuration) {
        duration = newDuration;
        validate();
    }
};

#endif // MEDIA_RESOURCE_H

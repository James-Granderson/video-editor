#include "timeline.h"
#include "proof.h"
#include "cut.h"

#include <iostream>

int main() {
    Timeline timeline;

    Video video("main", "video.mp4", 300.0);
    AudioData audio("main-audio", "audio.wav", 300.0);

    timeline.addVideo(video);
    timeline.addAudio(audio);

    std::cout << "=== VIDEO EDITOR ===\n\n";

    Proof::showTimeline(timeline);

    double startTime;
    double endTime;

    std::cout << "\nEnter cut start time: ";
    std::cin >> startTime;

    std::cout << "Enter cut end time: ";
    std::cin >> endTime;

    try {
        CutAction cut(startTime, endTime);

        std::cout << "\n=== CUT REQUEST ===\n";
        std::cout << "Start: " << cut.getStartTime() << "\n";
        std::cout << "End: " << cut.getEndTime() << "\n";
        std::cout << "Duration: "
                  << cut.getEndTime() - cut.getStartTime()
                  << "\n";
        std::cout << "===================\n";
    }
    catch (const std::exception& e) {
        std::cout << "\nCut rejected: " << e.what() << "\n";
    }

    return 0;
}

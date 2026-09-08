#include "proof.h"

#include <iostream>

//command = open Proof/Web/test.html

void Proof::showTimeline(const Timeline& timeline) {
    std::cout << "=== TIMELINE ===\n";

    std::cout << "\nVIDEO\n";

    for (const auto& video : timeline.getVideos()) {
        std::cout << "Identity: " << video.getIdentity() << "\n";
        std::cout << "Source: " << video.getSource() << "\n";
        std::cout << "Duration: " << video.getDuration() << "\n";
    }

    std::cout << "\nAUDIO\n";

    for (const auto& audio : timeline.getAudio()) {
        std::cout << "Identity: " << audio.getIdentity() << "\n";
        std::cout << "Source: " << audio.getSource() << "\n";
        std::cout << "Duration: " << audio.getDuration() << "\n";
    }

    std::cout << "\n================\n";
}

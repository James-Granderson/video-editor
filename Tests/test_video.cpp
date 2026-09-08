#include <cassert>
#include "video.h"
#include <iostream>
#include <stdexcept>

int main() {
    Video video("test-video", "test.mp4", 120.0);

    assert(video.getIdentity() == "test-video");
    assert(video.getSource() == "test.mp4");
    assert(video.getDuration() == 120.0);
    std::cout << "Video construction and getters: PASS\n";



// Empty identity must fail
try {
    Video badVideo("", "test.mp4", 120.0);
    assert(false);
} catch (const std::invalid_argument&) {
}

// Empty source must fail
try {
    Video badVideo("test-video", "", 120.0);
    assert(false);
} catch (const std::invalid_argument&) {
}

// Non-positive duration must fail
try {
    Video badVideo("test-video", "test.mp4", 0.0);
    assert(false);
} catch (const std::invalid_argument&) {
}

std::cout << "Video constraints: PASS\n";

return 0;
}
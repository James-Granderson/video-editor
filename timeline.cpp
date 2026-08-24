#include "timeline.h"

#include <stdexcept>

void Timeline::addVideo(const Video& video) {
    videos.push_back(video);
}

void Timeline::addAudio(const AudioData& audio) {
    this->audio.push_back(audio);
}

void Timeline::cut(double startTime, double endTime) {
    if (videos.empty() && audio.empty()) {
        throw std::invalid_argument("Cannot cut an empty timeline");
    }

    for (Video& video : videos) {
        video.cut(startTime, endTime);
    }

    for (AudioData& audioData : audio) {
        audioData.cut(startTime, endTime);
    }
}

const std::vector<Video>& Timeline::getVideos() const {
    return videos;
}

const std::vector<AudioData>& Timeline::getAudio() const {
    return audio;
}

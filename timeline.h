#pragma once

#include <vector>

#include "video.h"
#include "audio_data.h"

class Timeline {
private:
    std::vector<Video> videos;
    std::vector<AudioData> audio;

public:
    void addVideo(const Video& video);
    void addAudio(const AudioData& audio);
    void cut(double startTime, double endTime);

    const std::vector<Video>& getVideos() const;
    const std::vector<AudioData>& getAudio() const;
};

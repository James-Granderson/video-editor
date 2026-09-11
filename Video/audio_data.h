#include "audio_data.h"
#include <stdexcept>

AudioData::AudioData(std::shared_ptr<MediaResource> res, double volume)
    : resource(std::move(res)), volume(volume) {
    if (!resource) {
        throw std::invalid_argument("AudioData resource pointer cannot be null");
    }
    if (volume < 0.0) {
        throw std::invalid_argument("Volume cannot be negative");
    }
}

void AudioData::separate() {
    if (isLinked()) {
        // Re-assign resource pointer to a new heap copy preserving current snapshot
        resource = std::make_shared<MediaResource>(*resource);
    }
}

void AudioData::cut(double startTime, double endTime) {
    if (startTime < 0.0) {
        throw std::invalid_argument("Start time cannot be negative");
    }
    if (endTime <= startTime) {
        throw std::invalid_argument("End time must be greater than start time");
    }
    if (endTime > resource->getDuration()) {
        throw std::invalid_argument("End time cannot exceed current duration");
    }

    double newDuration = resource->getDuration() - (endTime - startTime);
    resource->setDuration(newDuration);
}
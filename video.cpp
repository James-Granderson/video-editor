#include "video.h"
#include <stdexcept>

Video::Video(std::shared_ptr<MediaResource> res) : resource(std::move(res)) {
    if (!resource) {
        throw std::invalid_argument("Video resource pointer cannot be null");
    }
}

void Video::separate() {
    if (isLinked()) {
        // Re-assign pointer to an independent heap copy preserving current snapshot
        resource = std::make_shared<MediaResource>(*resource);
    }
}

void Video::cut(double startTime, double endTime) {
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

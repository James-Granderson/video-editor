#include "video.h"

#include <stdexcept>

Video::Video(const std::string& identity,
             const std::string& source,
             double duration)
    : identity(identity), source(source), duration(duration) {

    if (identity.empty()) {
        throw std::invalid_argument("Video identity cannot be empty");
    }

    if (source.empty()) {
        throw std::invalid_argument("Video source cannot be empty");
    }

    if (duration <= 0.0) {
        throw std::invalid_argument("Video duration must be positive");
    }
}

const std::string& Video::getIdentity() const {
    return identity;
}

const std::string& Video::getSource() const {
    return source;
}

double Video::getDuration() const {
    return duration;
}

void Video::cut(double startTime, double endTime) {
    if (startTime < 0.0) {
        throw std::invalid_argument("Start time cannot be negative");
    }

    if (endTime <= startTime) {
        throw std::invalid_argument("End time must be greater than start time");
    }

    if (endTime > duration) {
        throw std::invalid_argument("End time cannot exceed video duration");
    }

    duration -= (endTime - startTime);
}

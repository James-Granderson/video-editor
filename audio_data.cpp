#include "audio_data.h"
#include <stdexcept>

// Single validation helper method
void AudioData::validate() const {
    if (identity.empty()) {
        throw std::invalid_argument("Audio identity cannot be empty");
    }
    if (source.empty()) {
        throw std::invalid_argument("Audio source cannot be empty");
    }
    if (duration <= 0.0) {
        throw std::invalid_argument("Audio duration must be positive");
    }
}

// Constructor delegates to validation helper
AudioData::AudioData(const std::string& identity, const std::string& source, double duration)
    : identity(identity), source(source), duration(duration) {
    validate();
}

// Getters
const std::string& AudioData::getIdentity() const { return identity; }
const std::string& AudioData::getSource() const { return source; }
double AudioData::getDuration() const { return duration; }

// Audio manipulation
void AudioData::cut(double startTime, double endTime) {
    if (startTime < 0.0) {
        throw std::invalid_argument("Start time cannot be negative");
    }
    if (endTime <= startTime) {
        throw std::invalid_argument("End time must be greater than start time");
    }
    if (endTime > duration) {
        throw std::invalid_argument("End time cannot exceed audio duration");
    }
    
    duration -= (endTime - startTime);
}

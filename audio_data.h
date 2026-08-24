#pragma once

#include <string>

class AudioData {
private:
    std::string identity;
    std::string source;
    double duration;

public:
    AudioData(const std::string& identity,
              const std::string& source,
              double duration);

    const std::string& getIdentity() const;
    const std::string& getSource() const;
    double getDuration() const;

    void cut(double startTime, double endTime);
};

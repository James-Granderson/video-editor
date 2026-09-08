#include "cut.h"
#include "../Video/timeline.h"

#include <stdexcept>

CutAction::CutAction(double startTime, double endTime)
    : startTime(startTime), endTime(endTime) {

    if (startTime < 0.0) {
        throw std::invalid_argument("Start time cannot be negative");
    }

    if (endTime <= startTime) {
        throw std::invalid_argument("End time must be greater than start time");
    }
}

void CutAction::execute(Timeline& timeline) {
    timeline.cut(startTime, endTime);
}

double CutAction::getStartTime() const {
    return startTime;
}

double CutAction::getEndTime() const {
    return endTime;
}

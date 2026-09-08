#pragma once

#include "action.h"

class CutAction : public Action {
private:
    double startTime;
    double endTime;

public:
    CutAction(double startTime, double endTime);

    void execute(Timeline& timeline) override;

    double getStartTime() const;
    double getEndTime() const;
};

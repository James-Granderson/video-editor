#pragma once

class Timeline;

class Action {
public:
    virtual ~Action() = default;

    virtual void execute(Timeline& timeline) = 0;
};

class UndoAction : public Action {
public:
    virtual void undo(Timeline& timeline) = 0;
};

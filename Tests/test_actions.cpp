#include "action.h"
#include <cassert>
#include <iostream>
#include <stdexcept>
#include "cut.h"

int main() {

    CutAction cut(10.0, 20.0);

    assert(cut.getStartTime() == 10.0);
    assert(cut.getEndTime() == 20.0);

    std::cout << "CutAction construction: PASS\n";

    try {
        CutAction badCut(-1.0, 10.0);
        assert(false);
    } catch (const std::invalid_argument&) {
    }

    try {
        CutAction badCut(20.0, 10.0);
        assert(false);
    } catch (const std::invalid_argument&) {
    }

    std::cout << "CutAction constraints: PASS\n";

    return 0;
}
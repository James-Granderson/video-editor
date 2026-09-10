```markdown
# Video Editor

A lightweight C++ video editing engine built around time-based media manipulation—select a timestamp or range on the timeline and perform precise edits.

## Features

* **Time-Based Trimming:** Select precise start and end timestamps to trim and cut audio and video assets (`AudioData::cut`).
* **Audio Track Management:** Encapsulates track identity, media source paths, and duration tracking (`AudioData`).
* **Video Clip Processing:** Manages video source properties, playheads, and time-constrained operations (`Video`).
* **Timeline Engine:** Positions media clips along a continuous temporal axis, coordinating edit points and multi-track synchronization (`Timeline`).

## Repository Structure

```text
.
├── audio_data.cpp   # Audio track validation and trim implementation
├── audio_data.h     # Audio track interface
├── video.cpp        # Video clip processing implementation
├── video.h          # Video clip interface
├── timeline.cpp     # Timeline management implementation
├── timeline.h       # Timeline interface
├── Main/            # Application entry point
├── Tests/           # Unit tests and edit assertion suites
└── Actions/         # Time-based editing actions and transformations

```

## Getting Started

### Prerequisites

* C++17 or higher compliant compiler (`g++`, `clang++`, or MSVC)

### Building and Running

Compile the source files using `g++`:

```bash
g++ -std=c++17 Main/*.cpp *.cpp -o video_editor
./video_editor

```

To run the test suite:

```bash
g++ -std=c++17 Tests/*.cpp *.cpp -o run_tests
./run_tests

```

## Usage Example

```cpp
#include "audio_data.h"
#include "video.h"
#include "timeline.h"

int main() {
    // 1. Instantiate audio clip with identity, source, and total duration (seconds)
    AudioData audio("track_01", "assets/audio.mp3", 120.0);

    // 2. Perform time-based edit: cut between 10.0s and 25.0s
    audio.cut(10.0, 25.0);

    return 0;
}

```

```

```

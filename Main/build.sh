#!/bin/bash
#./Main/build.sh

echo "Building Video Editor..."

g++ -std=c++11 -I Video -I Actions \
    Main/main.cpp \
    Video/video.cpp \
    Video/timeline.cpp \
    Video/audiodata.cpp \
    Actions/actions.cpp \
    Actions/add.cpp \
    Actions/cut.cpp \
    Actions/delete.cpp \
    Actions/export.cpp \
    Actions/move.cpp \
    Actions/undo.cpp \
    -o ve

echo "Building video tests..."

g++ -std=c++11 -I Video -I Actions \
    Tests/test_video.cpp \
    Video/video.cpp \
    Video/timeline.cpp \
    Video/audiodata.cpp \
    -o test_video

echo "Building action tests..."

g++ -std=c++11 -I Video -I Actions \
    Tests/test_actions.cpp \
    Video/video.cpp \
    Video/timeline.cpp \
    Video/audiodata.cpp \
    Actions/actions.cpp \
    Actions/add.cpp \
    Actions/cut.cpp \
    Actions/delete.cpp \
    Actions/export.cpp \
    Actions/move.cpp \
    Actions/undo.cpp \
    -o test_actions

echo "Build complete."
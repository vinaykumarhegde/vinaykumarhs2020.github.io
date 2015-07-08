#! /bin/bash
# This script runs cmake, make and runs the default input case.
# Please change the labyrinth.txt file with your input file.

cmake .
make

./longestPath labyrinth.txt


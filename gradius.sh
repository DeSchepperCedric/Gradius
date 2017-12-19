#!/bin/bash

[ -f ./build/CMakeCache.txt ] && rm ./build/CMakeCache.txt;
# create build folder if it doesnt exist
[ ! -d ./build ] && mkdir -p ./build;
cd build;
cmake ..
make;
make install;
# run game
../bin/Gradius;

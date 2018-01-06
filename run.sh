#!/bin/bash

[ -f ./build/CMakeCache.txt ] && rm ./build/CMakeCache.txt;

# create build folder if it doesnt exist
[ ! -d ./build ] && mkdir -p ./build;

# create bin folder if it doesnt exist
[ ! -d ./bin ] && mkdir -p ./bin;

cd build;
cmake ..
make;
make install;

# run game
../bin/Gradius;

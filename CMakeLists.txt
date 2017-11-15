


cmake_minimum_required(VERSION 3.5)
project(Gradius)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Entity.cpp Entity.h PlayerShip.cpp PlayerShip.h MovingEntity.cpp MovingEntity.h
        StationaryEntity.cpp StationaryEntity.h Game.cpp Game.h Stopwatch.cpp Stopwatch.h
        Transformation.cpp Transformation.h EntityRepresentation.cpp EntityRepresentation.h Model.cpp Model.h Controller.cpp Controller.h View.cpp View.h)
add_executable(Gradius ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Gradius ${SFML_LIBRARIES})
endif()
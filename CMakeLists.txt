


cmake_minimum_required(VERSION 3.5)
project(Gradius)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

 
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
ADD_EXECUTABLE(Gradius ${SOURCE_FILES})


SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake_modules/")
find_package(SFML 2 COMPONENTS system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Gradius ${SFML_LIBRARIES})
    
endif()


INSTALL(TARGETS Gradius DESTINATION ${PROJECT_SOURCE_DIR}/bin)






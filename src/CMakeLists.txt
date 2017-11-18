
file(GLOB_RECURSE SOURCE_FILES "*.cpp")
ADD_EXECUTABLE(Gradius ${SOURCE_FILES})

INSTALL(TARGETS Gradius DESTINATION ${PROJECT_SOURCE_DIR}/bin)


SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake_modules/")
find_package(SFML 2 COMPONENTS system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Gradius ${SFML_LIBRARIES})
    
endif()


INSTALL(TARGETS Gradius DESTINATION ${PROJECT_SOURCE_DIR}/bin)

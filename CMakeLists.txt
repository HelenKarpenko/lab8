cmake_minimum_required(VERSION 2.8)
project(lab8)
include_directories(include)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp src/Planet.cpp include/Planet.h src/PlanetStorage.cpp include/PlanetStorage.h src/FileProcessing.cpp include/FileProcessing.h src/Server.cpp include/Server.h src/TextProcessing.cpp include/TextProcessing.h)
add_executable(lab8 ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} jansson ssl)
target_link_libraries(${CMAKE_PROJECT_NAME} progbase-cpp progbase)
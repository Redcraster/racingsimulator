cmake_minimum_required(VERSION 3.10)

project(RacingSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(TransportLibrary)

add_executable(RacingSimulator main.cpp)

target_include_directories(RacingSimulator PUBLIC TransportLibrary)

target_link_libraries(RacingSimulator PRIVATE TransportLibrary)

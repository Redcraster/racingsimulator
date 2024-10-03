cmake_minimum_required(VERSION 3.10)

project(TransportLibrary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    Transport.cpp
    GroundTransport.cpp
    AirTransport.cpp
    Race.cpp
)

set(HEADERS
    Transport.h
    GroundTransport.h
    AirTransport.h
    Race.h
)

add_library(TransportLibrary SHARED ${SOURCES} ${HEADERS})

target_include_directories(TransportLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
cmake_minimum_required(VERSION 3.5.0)

project(SuikaGameClone VERSION 0.1.0 LANGUAGES C CXX)

find_package(SDL2 REQUIRED)
# find_package(SDL2_image REQUIRED)

file(GLOB SOURCES
    Sources/Utils/*
    Sources/Core/*
    Sources/Application/*
    Sources/Main.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(SuikaGameClone ${SOURCES})

target_link_libraries(SuikaGameClone SDL2::SDL2 SDL2::SDL2main)



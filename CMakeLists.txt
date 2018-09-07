#cmake

cmake_minimum_required(VERSION 3.5)

project(asteroids)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_custom_target(copy_commands ALL COMMAND
  cp "${CMAKE_BINARY_DIR}/compile_commands.json" "${CMAKE_SOURCE_DIR}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../lib")

set(LIST_TARGETS CACHE STRING "list of targets" FORCE)
set(LIST_SUBDIRS general_window game qresources main)

include(build.cmake)

message(STATUS "SUBDIRECTORIES: ${LIST_SUBDIRS}")
message(STATUS "TARGETS: ${LIST_TARGETS}")

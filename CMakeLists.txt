cmake_minimum_required(VERSION 3.5)
project(tomatoclock VERSION 1.0
              DESCRIPTION "command line count down task runner"
              LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if ("${CMAKE_EXPORT_COMPILE_COMMANDS}")
  message("generating compilation_command.json ... ")
else()
  message("note: no compilation_command.json")
endif()

# use force to enforce the change
set(MY_CACHE_VAR "VALUE" CACHE STRING "XXV" FORCE)

add_executable(tomatoclock
  main.cpp
  time.cpp
  time.cpp
  draw.h
  draw.cpp
  assets.h
  task.cpp
  task.h)

set_property(TARGET tomatoclock PROPERTY CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_compile_definitions(TEST_DRAW)
  set(DEBUG_COMPILATION_FLAG "")
  set(DEBUG_COMPILATION_FLAG "${DEBUG_COMPILATION_FLAG} -g")
  set(DEBUG_COMPILATION_FLAG "${DEBUG_COMPILATION_FLAG} -fsanitize=address")
  set_target_properties(tomatoclock
    PROPERTIES
    COMPILE_FLAGS "${DEBUG_COMPILATION_FLAG}"
    LINK_FLAGS "-fsanitize=address")
else()
  add_compile_definitions(MAIN)
endif()

target_link_libraries(tomatoclock termbox)
# add_library(termbox SHARED)

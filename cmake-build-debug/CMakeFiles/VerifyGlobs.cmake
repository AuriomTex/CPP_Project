# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.30
cmake_policy(SET CMP0009 NEW)

# PROJECT_SOURCES at CMakeLists.txt:42 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "D:/Unistuff/CPP-Project/src/*.cpp")
set(OLD_GLOB
  "D:/Unistuff/CPP-Project/src/ball.cpp"
  "D:/Unistuff/CPP-Project/src/main.cpp"
  "D:/Unistuff/CPP-Project/src/player.cpp"
  "D:/Unistuff/CPP-Project/src/square.cpp"
  "D:/Unistuff/CPP-Project/src/triangle.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "D:/Unistuff/CPP-Project/cmake-build-debug/CMakeFiles/cmake.verify_globs")
endif()

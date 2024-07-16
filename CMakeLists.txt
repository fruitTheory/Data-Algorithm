cmake_minimum_required(VERSION 3.29)
project(
  DataAlgorithm
  VERSION 0.1.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)
set(BUILD_DIR ${CMAKE_SOURCE_DIR}/build)

file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp)

add_executable(main ${SOURCES})

set_target_properties(main PROPERTIES 
  RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

target_include_directories(
  main PRIVATE
    src/Algorithms 
    src/DataStructures
    src/Includes
)

add_compile_options(/W4)

add_custom_target(
  run
  COMMAND ${BIN_DIR}/Release/main
  DEPENDS main
  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

add_custom_target(
  clean-all
  COMMAND ${CMAKE_COMMAND} -E rm -rf ${BUILD_DIR}
  COMMENT "Cleaning build artifacts"
)

#[[
Helpful commands:
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release

time make -C build -j 8  
time cmake --build build -- -j 8
msbuild ./build/MyProject.sln -p:Configuration=Release -m:8

cmake --build build --target clean-all
cmake --build build --target install
cmake --build build --config Release --target run
]]

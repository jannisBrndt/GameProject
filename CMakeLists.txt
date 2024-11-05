# Set minimum CMake version and project name
cmake_minimum_required(VERSION 3.10)
project(GameProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing in CMake
enable_testing()

# Game source files, excluding main.cpp for the test executable
file(GLOB_RECURSE GAME_SOURCES "src/Game/Components/*.cpp" "src/Game/Entities/*.cpp" "src/Game/Core/*.cpp" "src/Game/State/*.cpp")
list(REMOVE_ITEM GAME_SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")  # Exclude main.cpp from the test executable

# Add the main game executable
add_executable(GameProject ${GAME_SOURCES} src/main.cpp)

# Include directories
include_directories(include)

# Find and set up Google Test using FetchContent to automatically download and configure it
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Define test sources to automatically include all .cpp files in the tests directory
file(GLOB TEST_SOURCES "tests/*.cpp")

# Create the test executable combining game sources and test sources
add_executable(runTests ${GAME_SOURCES} ${TEST_SOURCES})

# Link Google Test to the test executable
target_link_libraries(runTests gtest gtest_main)

# Register the test executable with CTest so you can run it using `ctest`
add_test(NAME AllTests COMMAND runTests)

cmake_minimum_required(VERSION 3.1)
project(MySDK)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Add the source files of the SDK
file(GLOB SDK_SOURCES "sdk/*.cpp")

# Create the static library
add_library(MySDK STATIC ${SDK_SOURCES})

# Set the include directories for the SDK
target_include_directories(MySDK PUBLIC sdk)
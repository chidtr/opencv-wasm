cmake_minimum_required(VERSION 3.1)
project(MySDK)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

file(GLOB SDK_SOURCES "./*.cpp")

# Create the static library
add_library(MySDK STATIC ${SDK_SOURCES})

# Set the include directories for the SDK
# target_include_directories(MySDK PUBLIC sdk)
target_link_libraries(MySDK ${OpenCV_LIBS})
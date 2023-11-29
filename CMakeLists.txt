cmake_minimum_required(VERSION 3.1)
project(SdkProject)

# Use C++ 11 by default
set(CMAKE_CXX_STANDARD 14)

# Set Release as default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# Needed for opencv2/opencv.hpp
include_directories(/Users/chitran/Project/zozoglasses-sdk/opencv/include)

# Needed by opencv.hpp for opencv2/opencv_modules.hpp
include_directories(/Users/chitran/Project/zozoglasses-sdk/opencv/build_wasm)

# Needed by opencv_modules.hpp for every module
# file( GLOB opencv_include_modules "/third-party/opencv/modules/*/include" )
file(GLOB opencv_include_modules "/Users/chitran/Project/zozoglasses-sdk/opencv/modules/*/include")
include_directories(${opencv_include_modules})

include_directories(/Users/chitran/CLionProjects/opencv-wasm/sdk)

# Our hello world executable
add_executable(TestSdk src/binding.cpp Code/adding.cpp)

# Link to opencv.js precompiled libraries
file(GLOB opencv_js "/Users/chitran/Project/zozoglasses-sdk/opencv/build_wasm/lib/*.a")
file(GLOB sdk_wasm "/Users/chitran/CLionProjects/opencv-wasm/sdk/build/*.a")

target_link_libraries(TestSdk ${opencv_js})
target_link_libraries(TestSdk ${sdk_wasm})

set(COMPILE_FLAGS "-Wno-missing-prototypes")
set_target_properties(TestSdk PROPERTIES COMPILE_FLAGS ${COMPILE_FLAGS})
target_include_directories(TestSdk PUBLIC "/Users/chitran/Project/zozoglasses-sdk/wasm-sdk/emsdk/upstream/include")

set(EMSCRIPTEN_LINK_FLAGS "${EMSCRIPTEN_LINK_FLAGS} -s WASM=1")
set(EMSCRIPTEN_LINK_FLAGS "${EMSCRIPTEN_LINK_FLAGS} -std=c++1z -O3 --llvm-lto 1")
set(EMSCRIPTEN_LINK_FLAGS "${EMSCRIPTEN_LINK_FLAGS} -s ASSERTIONS=2")
set(EMSCRIPTEN_LINK_FLAGS "${EMSCRIPTEN_LINK_FLAGS} -s EXPORTED_RUNTIME_METHODS=cwrap -s MODULARIZE=1 -s EXPORT_NAME=SkinSdk -s EXPORT_NAME=SkinSdk -s ENVIRONMENT=web -s EXPORT_ES6=1 -s USE_ES6_IMPORT_META=0 -s NO_EXIT_RUNTIME=1")
set(EMSCRIPTEN_LINK_FLAGS "${EMSCRIPTEN_LINK_FLAGS} --memory-init-file 0 -s TOTAL_MEMORY=134217728 -s ALLOW_MEMORY_GROWTH=1")
set(EMSCRIPTEN_LINK_FLAGS "${EMSCRIPTEN_LINK_FLAGS} --bind")

set_target_properties(TestSdk PROPERTIES LINK_FLAGS "${EMSCRIPTEN_LINK_FLAGS} --bind")

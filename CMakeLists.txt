cmake_minimum_required(VERSION 3.10)
project(NodeBasedImageProcessor)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include directories
include_directories(include)

# Add executable
add_executable(NodeBasedImageProcessor
    src/main.cpp
    src/Node.cpp
    src/ImageInputNode.cpp
    src/OutputNode.cpp
    src/BrightnessContrastNode.cpp
    src/ColorChannelSplitterNode.cpp
)

# Link OpenCV libraries
target_link_libraries(NodeBasedImageProcessor ${OpenCV_LIBS})

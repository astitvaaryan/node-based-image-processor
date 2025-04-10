# # Minimum CMake version required
# cmake_minimum_required(VERSION 3.10)

# # Project name and version
# project(NodeBasedImageProcessor VERSION 1.0)

# # Set the C++ standard
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Set the OpenCV path manually if needed
# set(OpenCV_DIR "C:/Users/_Astitva_Aryan_/Downloads/opencv/build")

# #set(OpenCV_DIR "C:/opencv/build")  # Uncomment and update this line if CMake doesn't find OpenCV automatically

# # Find OpenCV
# find_package(OpenCV REQUIRED)

# # Include OpenCV and your own include directories
# include_directories(
#     ${OpenCV_INCLUDE_DIRS}
#     ${CMAKE_SOURCE_DIR}/include
# )

# # Add the main.cpp file directly
# set(SOURCES
#     ${CMAKE_SOURCE_DIR}/main.cpp
# )

# # Create the executable
# add_executable(NodeBasedImageProcessor ${SOURCES})

# # Link OpenCV
# target_link_libraries(NodeBasedImageProcessor ${OpenCV_LIBS})
cmake_minimum_required(VERSION 3.10)
project(NodeBasedImageProcessor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set OpenCV path (adjust if needed)
set(OpenCV_DIR "C:/Users/_Astitva_Aryan_/Downloads/opencv/build")

# Find OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Add source
add_executable(NodeBasedImageProcessor main.cpp)

# Link OpenCV
target_link_libraries(NodeBasedImageProcessor ${OpenCV_LIBS})

# Optional: set output path
set_target_properties(NodeBasedImageProcessor PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output")



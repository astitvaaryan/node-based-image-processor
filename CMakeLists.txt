<<<<<<< HEAD
# cmake_minimum_required(VERSION 3.10)
# project(NodeBasedImageProcessor)

# # Set C++ standard
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Set CMAKE_PREFIX_PATH for Qt6
# set(CMAKE_PREFIX_PATH "C:/Qt/6.8.3/msvc2022_64")

# # Set OpenCV path (adjust if needed)
# set(OpenCV_DIR "C:/Users/_Astitva_Aryan_/Downloads/opencv/build")

# # Find OpenCV
# find_package(OpenCV REQUIRED)
# if (OpenCV_FOUND)
#     message(STATUS "Found OpenCV: ${OpenCV_VERSION}")
#     include_directories(${OpenCV_INCLUDE_DIRS})
# else()
#     message(FATAL_ERROR "OpenCV not found. Please check OpenCV_DIR.")
# endif()

# # Find Qt6 Widgets
# find_package(Qt6 REQUIRED COMPONENTS Widgets)
# if (Qt6Widgets_FOUND)
#     message(STATUS "Found Qt6 Widgets")
# else()
#     message(FATAL_ERROR "Qt6 Widgets not found. Please ensure Qt is installed and configured.")
# endif()

# # Add source files
# set(SOURCES
#     main.cpp
#     include/Node.hpp
#     include/ImageInputNode.hpp
#     include/OutputNode.hpp
#     include/BrightnessContrastNode.hpp
#     include/ColorChannelSplitterNode.hpp
# )

# # Add executable
# add_executable(NodeBasedImageProcessor ${SOURCES})

# # Include directories for headers
# target_include_directories(NodeBasedImageProcessor PRIVATE include)

# # Link OpenCV libraries
# target_link_libraries(NodeBasedImageProcessor PRIVATE ${OpenCV_LIBS})

# # Link Qt6 Widgets
# target_link_libraries(NodeBasedImageProcessor PRIVATE Qt6::Widgets)

# # Optional: Set output directory for the executable
# set_target_properties(NodeBasedImageProcessor PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output"
# )

cmake_minimum_required(VERSION 3.10)
project(NodeBasedImageProcessor)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set CMAKE_PREFIX_PATH for Qt6
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.3/msvc2022_64")

#Set OpenCV path (adjust if needed)
set(OpenCV_DIR "C:/Users/_Astitva_Aryan_/Downloads/opencv/build")

# Find OpenCV
find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)
    message(STATUS "Found OpenCV: ${OpenCV_VERSION}")
    include_directories(${OpenCV_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "OpenCV not found. Please check OpenCV_DIR.")
endif()

# Find Qt6 Widgets
find_package(Qt6 REQUIRED COMPONENTS Widgets)
if (Qt6Widgets_FOUND)
    message(STATUS "Found Qt6 Widgets")
else()
    message(FATAL_ERROR "Qt6 Widgets not found. Please ensure Qt is installed and configured.")
endif()

# Add source files
set(SOURCES
    main.cpp
    include/Node.hpp
    include/ImageInputNode.hpp
    include/OutputNode.hpp
    include/BrightnessContrastNode.hpp
    include/ColorChannelSplitterNode.hpp
    MainWindow.cpp  # Add MainWindow source file
    include/MainWindow.hpp  # Add MainWindow header file
)

# Add executable
qt6_wrap_cpp(MOC_SOURCES include/MainWindow.hpp)
add_executable(NodeBasedImageProcessor ${SOURCES} ${MOC_SOURCES})
# add_executable(NodeBasedImageProcessor ${SOURCES})

# Include directories for headers
target_include_directories(NodeBasedImageProcessor PRIVATE include)

# Link OpenCV libraries
target_link_libraries(NodeBasedImageProcessor PRIVATE ${OpenCV_LIBS})

# Link Qt6 Widgets
target_link_libraries(NodeBasedImageProcessor PRIVATE Qt6::Widgets)
=======
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
>>>>>>> d1f3d5db0ced0e590ff9ead9b06dfe6e98239dd3

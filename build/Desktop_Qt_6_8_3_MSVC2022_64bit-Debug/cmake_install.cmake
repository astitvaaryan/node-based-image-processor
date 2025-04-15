# Install script for directory: /workspaces/node-based-image-processor

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
<<<<<<< HEAD:build/Desktop_Qt_6_8_3_MSVC2022_64bit-Debug/cmake_install.cmake
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/NodeBasedImageProcessor")
=======
  set(CMAKE_INSTALL_PREFIX "/usr/local")
>>>>>>> d1f3d5db0ced0e590ff9ead9b06dfe6e98239dd3:build/cmake_install.cmake
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
<<<<<<< HEAD:build/Desktop_Qt_6_8_3_MSVC2022_64bit-Debug/cmake_install.cmake
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
=======
    set(CMAKE_INSTALL_CONFIG_NAME "")
>>>>>>> d1f3d5db0ced0e590ff9ead9b06dfe6e98239dd3:build/cmake_install.cmake
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

<<<<<<< HEAD:build/Desktop_Qt_6_8_3_MSVC2022_64bit-Debug/cmake_install.cmake
if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
  file(WRITE "C:/Users/_Astitva_Aryan_/OneDrive/Desktop/node-based-image-processor/build/Desktop_Qt_6_8_3_MSVC2022_64bit-Debug/${CMAKE_INSTALL_MANIFEST}"
=======
string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/workspaces/node-based-image-processor/build/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> d1f3d5db0ced0e590ff9ead9b06dfe6e98239dd3:build/cmake_install.cmake
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")

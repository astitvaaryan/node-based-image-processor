# CMake generated Testfile for 
# Source directory: /workspaces/node-based-image-processor/opencv/modules/flann
# Build directory: /workspaces/node-based-image-processor/build/modules/flann
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_flann "/workspaces/node-based-image-processor/build/bin/opencv_test_flann" "--gtest_output=xml:opencv_test_flann.xml")
set_tests_properties(opencv_test_flann PROPERTIES  LABELS "Main;opencv_flann;Accuracy" WORKING_DIRECTORY "/workspaces/node-based-image-processor/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/workspaces/node-based-image-processor/opencv/cmake/OpenCVUtils.cmake;1799;add_test;/workspaces/node-based-image-processor/opencv/cmake/OpenCVModule.cmake;1365;ocv_add_test_from_target;/workspaces/node-based-image-processor/opencv/cmake/OpenCVModule.cmake;1123;ocv_add_accuracy_tests;/workspaces/node-based-image-processor/opencv/modules/flann/CMakeLists.txt;2;ocv_define_module;/workspaces/node-based-image-processor/opencv/modules/flann/CMakeLists.txt;0;")

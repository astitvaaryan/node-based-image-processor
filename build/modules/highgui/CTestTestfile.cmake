# CMake generated Testfile for 
# Source directory: /workspaces/node-based-image-processor/opencv/modules/highgui
# Build directory: /workspaces/node-based-image-processor/build/modules/highgui
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_highgui "/workspaces/node-based-image-processor/build/bin/opencv_test_highgui" "--gtest_output=xml:opencv_test_highgui.xml")
set_tests_properties(opencv_test_highgui PROPERTIES  LABELS "Main;opencv_highgui;Accuracy" WORKING_DIRECTORY "/workspaces/node-based-image-processor/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/workspaces/node-based-image-processor/opencv/cmake/OpenCVUtils.cmake;1799;add_test;/workspaces/node-based-image-processor/opencv/cmake/OpenCVModule.cmake;1365;ocv_add_test_from_target;/workspaces/node-based-image-processor/opencv/modules/highgui/CMakeLists.txt;311;ocv_add_accuracy_tests;/workspaces/node-based-image-processor/opencv/modules/highgui/CMakeLists.txt;0;")

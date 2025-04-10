#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    std::cout << "Node-Based Image Manipulation Interface" << std::endl;

    // Example: Load an image using OpenCV
    cv::Mat image = cv::imread("C:/Users/_Astitva_Aryan_/Downloads/sherry-christian-8Myh76_3M2U-unsplash.jpg", cv::IMREAD_COLOR);

    if (image.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }

    std::cout << "Image loaded successfully!" << std::endl;

    // Display the image in a window
    cv::imshow("Display window", image);
    cv::waitKey(0); // Wait for a keystroke in the window

    return 0;
}

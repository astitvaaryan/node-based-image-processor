#include "OutputNode.hpp"

cv::Mat OutputNode::process() {
    if (input.empty()) {
        throw std::runtime_error("No input image to save!");
    }
    cv::imwrite(outputPath, input);
    std::cout << "Image saved to: " << outputPath << std::endl;
    cv::imshow("Output Image", input);
    cv::waitKey(0);
    return input;
}

#include "BrightnessContrastNode.hpp"

cv::Mat BrightnessContrastNode::process() {
    if (input.empty()) {
        throw std::runtime_error("No input image to process!");
    }

    cv::Mat output;
    input.convertTo(output, -1, contrast, brightness);
    return output;
}

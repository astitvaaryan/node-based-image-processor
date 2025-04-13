#include "ColorChannelSplitterNode.hpp"

// cv::Mat ColorChannelSplitterNode::process() {
//     if (input.empty()) {
//         throw std::runtime_error("No input image to process!");
//     }

//     std::vector<cv::Mat> channels(input.channels());
//     cv::split(input, channels);

//     // Optionally, output grayscale representation of each channel
//     for (size_t i = 0; i < channels.size(); ++i) {
//         std::cout << "Channel " << i << " dimensions: " << channels[i].size() << std::endl;
//     }

//     return input; // Return the original image or modify as needed
// }

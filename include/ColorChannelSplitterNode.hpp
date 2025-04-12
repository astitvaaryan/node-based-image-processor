#ifndef COLORCHANNELSPLITTERNODE_HPP
#define COLORCHANNELSPLITTERNODE_HPP

#include "Node.hpp"

class ColorChannelSplitterNode : public Node {
public:
    cv::Mat process() override {
        if (input.empty()) {
            throw std::runtime_error("No input image to process!");
        }

        std::vector<cv::Mat> channels(input.channels());
        cv::split(input, channels);

        // Optionally, output grayscale representation of each channel
        for (size_t i = 0; i < channels.size(); ++i) {
            std::cout << "Channel " << i << " dimensions: " << channels[i].size() << std::endl;
        }

        // Pass the output to the next node
        for (Node* nextNode : nextNodes) {
            nextNode->setInput(input);
            nextNode->process();
        }

        return input; // Return the original image or modify as needed
    }
};

#endif // COLORCHANNELSPLITTERNODE_HPP

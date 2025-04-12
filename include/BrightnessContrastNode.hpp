#ifndef BRIGHTNESSCONTRASTNODE_HPP
#define BRIGHTNESSCONTRASTNODE_HPP

#include "Node.hpp"

class BrightnessContrastNode : public Node {
public:
    BrightnessContrastNode(int brightness, double contrast)
        : brightness(brightness), contrast(contrast) {}

    cv::Mat process() override {
        if (input.empty()) {
            throw std::runtime_error("No input image to process!");
        }

        cv::Mat output;
        input.convertTo(output, -1, contrast, brightness);

        // Pass the output to the next node
        for (Node* nextNode : nextNodes) {
            nextNode->setInput(output);
            nextNode->process();
        }

        return output;
    }

private:
    int brightness;
    double contrast;
};

#endif // BRIGHTNESSCONTRASTNODE_HPP

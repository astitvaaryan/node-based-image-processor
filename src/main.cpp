#include <iostream>
#include "ImageInputNode.hpp"
#include "OutputNode.hpp"
#include "BrightnessContrastNode.hpp"
#include "ColorChannelSplitterNode.hpp"

int main() {
    try {
        // Create nodes
        ImageInputNode inputNode("path/to/your/image.jpg");
        BrightnessContrastNode brightnessContrastNode(50, 1.5);
        ColorChannelSplitterNode channelSplitterNode;
        OutputNode outputNode;

        // Connect nodes
        inputNode.connectTo(&brightnessContrastNode);
        brightnessContrastNode.connectTo(&channelSplitterNode);
        channelSplitterNode.connectTo(&outputNode);

        // Process nodes
        cv::Mat image = inputNode.process();
        brightnessContrastNode.setInput(image);
        cv::Mat adjustedImage = brightnessContrastNode.process();
        channelSplitterNode.setInput(adjustedImage);
        channelSplitterNode.process();

        // Set output path and save image
        outputNode.setInput(adjustedImage);
        outputNode.setOutputPath("path/to/save/processed_image.jpg");
        outputNode.process();

        std::cout << "Image processing complete!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}

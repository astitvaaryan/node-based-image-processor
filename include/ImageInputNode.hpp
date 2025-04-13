#ifndef IMAGEINPUTNODE_HPP
#define IMAGEINPUTNODE_HPP

#include "Node.hpp"

class ImageInputNode : public Node {
public:
    ImageInputNode(const std::string& filePath) : filePath(filePath) {}

    cv::Mat process() override {
        input = cv::imread(filePath, cv::IMREAD_COLOR);
        if (input.empty()) {
            throw std::runtime_error("Could not open or find the image!");
        }
        std::cout << "Image loaded: " << filePath << std::endl;
        std::cout << "Dimensions: " << input.size() << std::endl;
        std::cout << "Channels: " << input.channels() << std::endl;

        // Pass the output to the next node
        // for (Node* nextNode : nextNodes) {
        //     nextNode->setInput(input);
        //     nextNode->process();
        // }

        for (Node* nextNode : nextNodes) {
            std::cout << "Passing image to next node..." << std::endl;
            try {
                nextNode->setInput(input);
                nextNode->process();
                std::cout << "Next node processed successfully." << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Error in next node: " << e.what() << std::endl;
                throw;
            }
        }

        return input;
    }

private:
    std::string filePath;
};

#endif // IMAGEINPUTNODE_HPP

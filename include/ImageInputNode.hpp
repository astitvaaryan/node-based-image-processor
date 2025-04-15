#ifndef IMAGEINPUTNODE_HPP
#define IMAGEINPUTNODE_HPP

#include "Node.hpp"

class ImageInputNode : public Node {
public:
    // Constructor using file path
    ImageInputNode(const std::string& filePath) : filePath(filePath), useFile(true) {}

    // Default constructor (for direct image setting)
    ImageInputNode() : useFile(false) {}

    // Set image directly (used when modifying brightness/contrast dynamically)
    void setImage(const cv::Mat& img) {
        input = img.clone();
        useFile = false;
    }

    // Get current image
    cv::Mat getImage() const {
        return input;
    }

    cv::Mat process() override {
        if (useFile) {
            input = cv::imread(filePath, cv::IMREAD_COLOR);
            if (input.empty()) {
                throw std::runtime_error("Could not open or find the image!");
            }
            std::cout << "Image loaded from file: " << filePath << std::endl;
        } else {
            std::cout << "Image used from memory (setImage)." << std::endl;
        }

        std::cout << "Dimensions: " << input.size() << std::endl;
        std::cout << "Channels: " << input.channels() << std::endl;

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

    bool useFile;

};

#endif // IMAGEINPUTNODE_HPP

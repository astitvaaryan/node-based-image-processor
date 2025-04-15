#ifndef IMAGEINPUTNODE_HPP
#define IMAGEINPUTNODE_HPP

#include "Node.hpp"

class ImageInputNode : public Node {
public:
<<<<<<< HEAD
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
=======
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

>>>>>>> d1f3d5db0ced0e590ff9ead9b06dfe6e98239dd3
        return input;
    }

private:
    std::string filePath;
<<<<<<< HEAD
    bool useFile;
=======
>>>>>>> d1f3d5db0ced0e590ff9ead9b06dfe6e98239dd3
};

#endif // IMAGEINPUTNODE_HPP

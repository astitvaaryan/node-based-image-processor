
// #ifndef OUTPUTNODE_HPP
// #define OUTPUTNODE_HPP

// #include "Node.hpp"

// class OutputNode : public Node {
// public:
//     cv::Mat process() override {
//         if (input.empty()) {
//             throw std::runtime_error("No input image to save!");
//         }
//         cv::imwrite(outputPath, input);
//         std::cout << "Image saved to: " << outputPath << std::endl;
//         cv::imshow("Output Image", input);
//         cv::waitKey(0);

//         // Pass the output to the next node
//         for (Node* nextNode : nextNodes) {
//             nextNode->setInput(input);
//             nextNode->process();
//         }

//         return input;
//     }
// };

// #endif // OUTPUTNODE_HPP




// #ifndef OUTPUTNODE_HPP
// #define OUTPUTNODE_HPP

// #include "Node.hpp"
// #include <iostream>
// #include <stdexcept>

// class OutputNode : public Node {
// public:
//     void setOutputPath(const std::string& path) {
//         outputPath = path;
//     }

//     cv::Mat process() override {
//         if (input.empty()) {
//             throw std::runtime_error("No input image to save!");
//         }
//         cv::imwrite(outputPath, input);
//         std::cout << "Image saved to: " << outputPath << std::endl;
//         cv::imshow("Output Image", input);
//         cv::waitKey(0);
//         return input;
//     }


//         if (outputPath.empty()) {
//             throw std::runtime_error("Output path is not set!");
//         }

//         std::cout << "Attempting to save image to: " << outputPath << std::endl;

//         // Attempt to save the image
//         if (!cv::imwrite(outputPath, input)) {
//             throw std::runtime_error("Failed to save the image to: " + outputPath);
//         }

//         std::cout << "Image saved successfully to: " << outputPath << std::endl;

//         // Optionally display the image
//         cv::imshow("Output Image", input);
//         cv::waitKey(0);

//         // Pass the output to the next node
//         for (Node* nextNode : nextNodes) {
//             nextNode->setInput(input);
//             nextNode->process();
//         }

//         return input;
//     }

// private:
//     std::string outputPath;
// };

// #endif // OUTPUTNODE_HPP




#ifndef OUTPUTNODE_HPP
#define OUTPUTNODE_HPP

#include "Node.hpp"
#include <iostream>
#include <stdexcept>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

class OutputNode : public Node {
public:
    void setOutputPath(const std::string& path) {
        outputPath = path;
    }

    cv::Mat process() override {
        if (input.empty()) {
            throw std::runtime_error("No input image to save!");
        }

        if (outputPath.empty()) {
            throw std::runtime_error("Output path is not set!");
        }

        std::cout << "Attempting to save image to: " << outputPath << std::endl;

        // Attempt to save the image
        if (!cv::imwrite(outputPath, input)) {
            throw std::runtime_error("Failed to save the image to: " + outputPath);
        }

        std::cout << "Image saved successfully to: " << outputPath << std::endl;

        // Optionally display the image
        cv::imshow("Output Image", input);
        cv::waitKey(0);

        // Pass the output to the next node
        for (Node* nextNode : nextNodes) {
            nextNode->setInput(input);
            nextNode->process();
        }

        return input;
    }

private:
    std::string outputPath;
};

#endif // OUTPUTNODE_HPP

<<<<<<< HEAD
=======
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

>>>>>>> d1f3d5db0ced0e590ff9ead9b06dfe6e98239dd3
#ifndef OUTPUTNODE_HPP
#define OUTPUTNODE_HPP

#include "Node.hpp"
<<<<<<< HEAD

class OutputNode : public Node {
public:
=======
#include <iostream>
#include <stdexcept>

class OutputNode : public Node {
public:
    void setOutputPath(const std::string& path) {
        outputPath = path;
    }

>>>>>>> d1f3d5db0ced0e590ff9ead9b06dfe6e98239dd3
    cv::Mat process() override {
        if (input.empty()) {
            throw std::runtime_error("No input image to save!");
        }
<<<<<<< HEAD
        cv::imwrite(outputPath, input);
        std::cout << "Image saved to: " << outputPath << std::endl;
        cv::imshow("Output Image", input);
        cv::waitKey(0);
        return input;
    }
};

#endif // OUTPUTNODE_HPP
=======

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
>>>>>>> d1f3d5db0ced0e590ff9ead9b06dfe6e98239dd3

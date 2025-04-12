#ifndef OUTPUTNODE_HPP
#define OUTPUTNODE_HPP

#include "Node.hpp"

class OutputNode : public Node {
public:
    cv::Mat process() override {
        if (input.empty()) {
            throw std::runtime_error("No input image to save!");
        }
        cv::imwrite(outputPath, input);
        std::cout << "Image saved to: " << outputPath << std::endl;
        cv::imshow("Output Image", input);
        cv::waitKey(0);

        // Pass the output to the next node
        for (Node* nextNode : nextNodes) {
            nextNode->setInput(input);
            nextNode->process();
        }

        return input;
    }
};

#endif // OUTPUTNODE_HPP

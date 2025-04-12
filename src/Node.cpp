#include "Node.hpp"

void Node::setInput(const cv::Mat& input) {
    this->input = input;
}

void Node::setOutputPath(const std::string& path) {
    this->outputPath = path;
}

#ifndef NODE_HPP
#define NODE_HPP
#include "opencv2/opencv.hpp"

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

class Node {
public:
    virtual ~Node() = default;
    virtual cv::Mat process() = 0;
    virtual void setInput(const cv::Mat& input) { this->input = input; }
    virtual void setOutputPath(const std::string& path) { this->outputPath = path; }
    virtual void connectTo(Node* nextNode) { this->nextNodes.push_back(nextNode); }

protected:
    cv::Mat input;
    std::string outputPath;
    std::vector<Node*> nextNodes;
};

#endif // NODE_HPP

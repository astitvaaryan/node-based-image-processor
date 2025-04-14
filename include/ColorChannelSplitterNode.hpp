// #ifndef COLORCHANNELSPLITTERNODE_HPP
// #define COLORCHANNELSPLITTERNODE_HPP

// #include "Node.hpp"
// #include <iostream>
// #include <vector>

// class ColorChannelSplitterNode : public Node {
// public:
//     ColorChannelSplitterNode() : selectedChannel(0) {}

//     void setChannelIndex(int index) {
//         selectedChannel = index;
//     }

//     cv::Mat process() override {
//         if (input.empty()) {
//             throw std::runtime_error("No input image to process!");
//         }

//         std::vector<cv::Mat> channels;
//         cv::split(input, channels);

//         if (selectedChannel < 0 || selectedChannel >= static_cast<int>(channels.size())) {
//             throw std::runtime_error("Invalid channel index selected!");
//         }

//         std::cout << "Displaying channel " << selectedChannel << " | Dimensions: "
//                   << channels[selectedChannel].rows << "x" << channels[selectedChannel].cols << std::endl;

//         return channels[selectedChannel]; // This is already a grayscale Mat
//     }

// private:
//     int selectedChannel;
// };

// #endif // COLORCHANNELSPLITTERNODE_HPP




#ifndef COLORCHANNELSPLITTERNODE_HPP
#define COLORCHANNELSPLITTERNODE_HPP

#include "Node.hpp"
#include <opencv2/opencv.hpp>
#include <vector>
#include <QDebug>

class ColorChannelSplitterNode : public Node {
public:
    ColorChannelSplitterNode() : channelIndex(-1) {}

    void setInput(const cv::Mat& img) override {
        inputImage = img.clone();
        qDebug() << "Input image set with size:" << img.cols << "x" << img.rows;
    }

    void setChannelIndex(int index) {
        channelIndex = index;
        qDebug() << "Channel index set to:" << channelIndex;
    }

    cv::Mat process() override {
        if (inputImage.empty()) {
            qDebug() << "No input image to process!";
            return cv::Mat();
        }

        if (channelIndex < 0 || channelIndex > 2) {
            return inputImage;
        }

        std::vector<cv::Mat> channels;
        cv::split(inputImage, channels);  // BGR split

        if (channels.size() < 3) {
            qDebug() << "Input image has fewer than 3 channels!";
            return inputImage;
        }

        qDebug() << "Extracting grayscale image of channel index:" << channelIndex;

        // Return only the selected channel as a single-channel grayscale image
        return channels[channelIndex];
    }

private:
    cv::Mat inputImage;
    int channelIndex;
};

#endif // COLORCHANNELSPLITTERNODE_HPP






// #ifndef COLORCHANNELSPLITTERNODE_HPP
// #define COLORCHANNELSPLITTERNODE_HPP

// #include "Node.hpp"
// #include <opencv2/opencv.hpp>
// #include <vector>
// #include <QDebug>

// class ColorChannelSplitterNode : public Node {
// public:
//     ColorChannelSplitterNode() : channelIndex(-1) {}

//     void setInput(const cv::Mat& img) override {
//         inputImage = img.clone();
//     }

//     void setChannelIndex(int index) {
//         channelIndex = index;
//     }

//     cv::Mat process() override {
//         if (inputImage.empty()) {
//             qDebug() << "No input image to process!";
//             return cv::Mat();
//         }

//         if (channelIndex < 0 || channelIndex > 2) {
//             qDebug() << "Showing original image (channelIndex:" << channelIndex << ")";
//             return inputImage;  // Original color image
//         }

//         std::vector<cv::Mat> channels;
//         cv::split(inputImage, channels);  // BGR

//         if (channels.size() < 3) {
//             qDebug() << "Image has fewer than 3 channels!";
//             return inputImage;
//         }

//         // Create a blank image and place the selected channel in the right position
//         std::vector<cv::Mat> merged = { cv::Mat::zeros(channels[0].size(), channels[0].type()),
//                                        cv::Mat::zeros(channels[0].size(), channels[0].type()),
//                                        cv::Mat::zeros(channels[0].size(), channels[0].type()) };

//         merged[channelIndex] = channels[channelIndex];

//         cv::Mat colorChannel;
//         cv::merge(merged, colorChannel);
//         return colorChannel;
//     }


// private:
//     cv::Mat inputImage;
//     int channelIndex;
// };

// #endif // COLORCHANNELSPLITTERNODE_HPP




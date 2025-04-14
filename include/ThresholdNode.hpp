// #ifndef THRESHOLDNODE_HPP
// #define THRESHOLDNODE_HPP

// #include "Node.hpp"
// #include <opencv2/opencv.hpp>


// class ThresholdNode : public Node {
// private:
//     double thresholdValue;
//     double maxValue;
//     int thresholdType;
//     int thresholdMin = 0;
//     int thresholdMax = 255;

//     cv::Mat inputImage;

// public:
//     ThresholdNode(double thresholdValue = 128.0, double maxValue = 255.0, int thresholdType = cv::THRESH_BINARY)
//         : thresholdValue(thresholdValue), maxValue(maxValue), thresholdType(thresholdType) {}

//     void setThresholdValue(double value) { thresholdValue = value; }
//     void setMaxValue(double value) { maxValue = value; }
//     void setThresholdMin(int value) { thresholdMin = value; }
//     void setThresholdMax(int value) { thresholdMax = value; }
//     void setThresholdType(int type) { thresholdType = type; }


//     void setInput(const cv::Mat& img) override {
//         inputImage = img.clone();
//     }

//     cv::Mat process() override {
//         if (inputImage.empty()) {
//             std::cerr << "Error: No input image set!" << std::endl;
//             return cv::Mat();
//         }

//         cv::Mat output;
//         cv::threshold(inputImage, output, thresholdValue, maxValue, thresholdType);
//         return output;
//     }
// };

// #endif  // THRESHOLDNODE_HPP






// #ifndef THRESHOLDNODE_HPP
// #define THRESHOLDNODE_HPP

// #include "Node.hpp"
// #include <opencv2/opencv.hpp>
// #include <iostream>

// enum class ThresholdMethod {
//     Binary,
//     Otsu,
//     Adaptive
// };

// class ThresholdNode : public Node {
// private:
//     double thresholdValue;
//     double maxValue;
//     ThresholdMethod method;
//     int thresholdType;

//     int blockSize;   // For adaptive threshold
//     double C;

//     cv::Mat inputImage;

// public:
//     ThresholdNode(double thresholdValue = 128.0, double maxValue = 255.0,
//                   ThresholdMethod method = ThresholdMethod::Binary,
//                   int thresholdType = cv::THRESH_BINARY)
//         : thresholdValue(thresholdValue),
//         maxValue(maxValue),
//         method(method),
//         thresholdType(thresholdType),
//         blockSize(11),
//         C(2.0) {}

//     void setInput(const cv::Mat& img) override {
//         inputImage = img.clone();
//     }

//     void setThresholdValue(double value) { thresholdValue = value; }
//     void setMaxValue(double value) { maxValue = value; }
//     void setThresholdType(int type) { thresholdType = type; }
//     void setMethod(ThresholdMethod m) { method = m; }
//     void setBlockSize(int b) { blockSize = b; }
//     void setC(double c) { C = c; }

//     cv::Mat process() override {
//         if (inputImage.empty()) {
//             std::cerr << "Error: No input image set!" << std::endl;
//             return cv::Mat();
//         }

//         cv::Mat gray;
//         if (inputImage.channels() > 1)
//             cv::cvtColor(inputImage, gray, cv::COLOR_BGR2GRAY);
//         else
//             gray = inputImage;

//         cv::Mat output;

//         switch (method) {
//         case ThresholdMethod::Binary:
//             cv::threshold(gray, output, thresholdValue, maxValue, thresholdType);
//             break;

//         case ThresholdMethod::Otsu:
//             cv::threshold(gray, output, 0, maxValue, cv::THRESH_BINARY | cv::THRESH_OTSU);
//             break;

//         case ThresholdMethod::Adaptive:
//             cv::adaptiveThreshold(gray, output, maxValue,
//                                   cv::ADAPTIVE_THRESH_GAUSSIAN_C,
//                                   thresholdType, blockSize, C);
//             break;
//         }

//         return output;
//     }

//     // Optional: for histogram plotting in GUI
//     cv::Mat getHistogramImage(int histSize = 256, int histHeight = 400) {
//         if (inputImage.empty()) return cv::Mat();

//         cv::Mat gray;
//         if (inputImage.channels() > 1)
//             cv::cvtColor(inputImage, gray, cv::COLOR_BGR2GRAY);
//         else
//             gray = inputImage;

//         cv::Mat hist;
//         float range[] = { 0, 256 };
//         const float* histRange = { range };
//         cv::calcHist(&gray, 1, 0, cv::Mat(), hist, 1, &histSize, &histRange);

//         // Normalize and draw histogram
//         cv::Mat histImage(histHeight, histSize, CV_8UC3, cv::Scalar(255, 255, 255));
//         cv::normalize(hist, hist, 0, histHeight, cv::NORM_MINMAX);

//         for (int i = 1; i < histSize; i++) {
//             cv::line(histImage,
//                      cv::Point(i - 1, histHeight - cvRound(hist.at<float>(i - 1))),
//                      cv::Point(i, histHeight - cvRound(hist.at<float>(i))),
//                      cv::Scalar(0, 0, 0), 2);
//         }

//         return histImage;
//     }
// };

// #endif  // THRESHOLDNODE_HPP



#ifndef BLURNODE_HPP
#define BLURNODE_HPP

#include "Node.hpp"
#include <opencv2/opencv.hpp>
#include <QDebug>

class BlurNode : public Node {
public:
    enum class BlurType { Uniform, Directional };

    BlurNode() : radius(5), blurType(BlurType::Uniform) {}

    void setInput(const cv::Mat& img) override {
        inputImage = img.clone();
    }

    void setRadius(int r) {
        radius = std::clamp(r, 1, 20);
        qDebug() << "Blur radius set to:" << radius;
    }

    void setBlurType(BlurType type) {
        blurType = type;
        qDebug() << "Blur type set to:" << (type == BlurType::Uniform ? "Uniform" : "Directional");
    }

    cv::Mat getKernelPreview() {
        if (blurType == BlurType::Uniform) {
            cv::Mat kernel = cv::getGaussianKernel(2 * radius + 1, radius * 1.5, CV_32F);
            return kernel * kernel.t();  // 2D Gaussian kernel
        } else {
            cv::Mat kernel = cv::Mat::zeros(2 * radius + 1, 2 * radius + 1, CV_32F);
            kernel.row(radius).setTo(1.0f / (2 * radius + 1));  // Horizontal blur line
            return kernel;
        }
    }

    cv::Mat process() override {
        if (inputImage.empty()) {
            qDebug() << "No input image to process!";
            return cv::Mat();
        }

        if (radius < 1 || radius > 20) {
            qDebug() << "Invalid blur radius!";
            return inputImage;
        }

        cv::Mat outputImage;

        if (blurType == BlurType::Uniform) {
            double sigma = radius * 1.5;
            cv::GaussianBlur(inputImage, outputImage, cv::Size(2 * radius + 1, 2 * radius + 1), sigma);
        } else if (blurType == BlurType::Directional) {
            cv::Mat kernel = getKernelPreview();  // Use preview kernel
            cv::filter2D(inputImage, outputImage, -1, kernel);
        }

        return outputImage;
    }

private:
    cv::Mat inputImage;
    int radius;
    BlurType blurType;
};

#endif // BLURNODE_HPP




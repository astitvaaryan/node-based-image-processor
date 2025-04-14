#ifndef BRIGHTNESSCONTRASTNODE_HPP
#define BRIGHTNESSCONTRASTNODE_HPP

#include "Node.hpp"

class BrightnessContrastNode : public Node {
public:
    // Constructor
    BrightnessContrastNode(int brightness = 0, double contrast = 1.0)
        : brightness(brightness), contrast(contrast) {}

    // Process the input image and apply brightness/contrast adjustments
    cv::Mat process() override {
        if (input.empty()) {
            throw std::runtime_error("No input image to process!");
        }

        cv::Mat output;
        // Normalize contrast and brightness
        double alpha = contrast;          // keep as-is (1.0 = no change)
        int beta = brightness - 50;       // normalize to -50 to +50 (centered at 0)
        input.convertTo(output, -1, alpha, beta);
        return output;
    }

    // Setters for brightness and contrast
    void setBrightness(int brightness) { this->brightness = brightness; }
    void setContrast(double contrast) { this->contrast = contrast; }

private:
    int brightness;       // Brightness adjustment value
    double contrast;      // Contrast adjustment factor
};

#endif // BRIGHTNESSCONTRASTNODE_HPP

#ifndef BRIGHTNESSCONTRASTNODE_HPP
#define BRIGHTNESSCONTRASTNODE_HPP

#include "Node.hpp"

class BrightnessContrastNode : public Node {
public:
<<<<<<< HEAD
    // Constructor
    BrightnessContrastNode(int brightness = 0, double contrast = 1.0)
        : brightness(brightness), contrast(contrast) {}

    // Process the input image and apply brightness/contrast adjustments
=======
    BrightnessContrastNode(int brightness, double contrast)
        : brightness(brightness), contrast(contrast) {}

>>>>>>> d1f3d5db0ced0e590ff9ead9b06dfe6e98239dd3
    cv::Mat process() override {
        if (input.empty()) {
            throw std::runtime_error("No input image to process!");
        }

        cv::Mat output;
<<<<<<< HEAD
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
=======
        input.convertTo(output, -1, contrast, brightness);

        // Pass the output to the next node
        for (Node* nextNode : nextNodes) {
            nextNode->setInput(output);
            nextNode->process();
        }

        return output;
    }

private:
    int brightness;
    double contrast;
>>>>>>> d1f3d5db0ced0e590ff9ead9b06dfe6e98239dd3
};

#endif // BRIGHTNESSCONTRASTNODE_HPP

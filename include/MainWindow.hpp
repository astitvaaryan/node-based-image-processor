#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDockWidget>
#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QComboBox>
#include "ImageInputNode.hpp"
#include "OutputNode.hpp"
#include "BrightnessContrastNode.hpp"
#include "ColorChannelSplitterNode.hpp"
#include "BlurNode.hpp"
// #include "ThresholdNode.hpp"

// QT_BEGIN_NAMESPACE
// namespace Ui { class MainWindow; }
// QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void openImage();
    void saveImage();
    void processImage();
    void displayChannelImage(const cv::Mat &channelImage);
    void showKernelPreview();

    // void onThresholdValueChanged(int value);
    // void onMethodChanged(int index);
    // void onLoadImage();
    // void applyThresholding();


private:
    QGraphicsScene* scene;
    QGraphicsView* view;
    QDockWidget* propertiesPanel;
    QSlider* brightnessSlider;
    QSlider* contrastSlider;
    QPushButton* processButton;
    QComboBox* channelSelector;
    QSlider* blurRadiusSlider;
    QComboBox* blurTypeSelector;
    // QSlider* thresholdSlider;
    // QLabel* thresholdLabel;
    // QGraphicsScene *sceneOriginal;
    // QGraphicsScene *sceneProcessed;
    // QGraphicsScene *sceneHistogram;


    ImageInputNode* inputNode;
    BrightnessContrastNode* brightnessContrastNode;
    ColorChannelSplitterNode* splitterNode;
    OutputNode* outputNode;
    BlurNode* blurNode;
   // ThresholdNode* thresholdNode;

    int channelIndex = -1;
};

#endif // MAINWINDOW_HPP


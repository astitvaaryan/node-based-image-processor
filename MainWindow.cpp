// #include "MainWindow.hpp"
// #include <filesystem>
// #include <QComboBox>
// #include <QThread>
// #include <QImage>
// #include <QPixmap>
// #include <QMessageBox>
// #include <QHBoxLayout>
// #include <QtConcurrent/QtConcurrent>



// MainWindow::MainWindow(QWidget* parent)
//     : QMainWindow(parent),
//     inputNode(new ImageInputNode("")),
//     brightnessContrastNode(new BrightnessContrastNode(50, 1.5)),
//     splitterNode(new ColorChannelSplitterNode()),
//     outputNode(new OutputNode()),
//     blurNode(new BlurNode()),
//     thresholdNode(new ThresholdNode()) {

//     // Create a central widget and layout for the full view
//     QWidget* centralWidget = new QWidget(this);
//     QVBoxLayout* centralLayout = new QVBoxLayout(centralWidget);

//     // Set up the canvas (view)
//     scene = new QGraphicsScene(this);
//     view = new QGraphicsView(scene, this);
//     centralLayout->addWidget(view);  // Add view to the layout

//     // Channel selector (ComboBox) setup
//     channelSelector = new QComboBox(this);
//     channelSelector->addItem("Original Color Image", -1);
//     channelSelector->addItem("Blue Channel", 0);   // Blue channel = index 0
//     channelSelector->addItem("Red Channel", 2);    // Red channel = index 1
//     channelSelector->addItem("Green Channel", 1);  // Green channel = index 2

//     centralLayout->addWidget(channelSelector);

//     // **Blur Node Controls**
//     QLabel* blurLabel = new QLabel("Blur Radius:");
//     blurRadiusSlider = new QSlider(Qt::Horizontal);
//     blurRadiusSlider->setRange(1, 20);
//     blurRadiusSlider->setValue(5);

//     QLabel* blurTypeLabel = new QLabel("Blur Type:");
//     blurTypeSelector = new QComboBox(this);
//     blurTypeSelector->addItem("Uniform");
//     blurTypeSelector->addItem("Directional");

//     centralLayout->addWidget(blurLabel);
//     centralLayout->addWidget(blurRadiusSlider);
//     centralLayout->addWidget(blurTypeLabel);
//     centralLayout->addWidget(blurTypeSelector);

//     // Set the final layout to central widget
//     centralWidget->setLayout(centralLayout);
//     setCentralWidget(centralWidget);

//     // Add a sample node to the canvas
//     QGraphicsRectItem* node = scene->addRect(0, 0, 100, 50);
//     node->setFlag(QGraphicsItem::ItemIsMovable);

//     // Set up the properties panel
//     propertiesPanel = new QDockWidget("Properties", this);
//     QWidget* propertiesWidget = new QWidget();
//     QVBoxLayout* layout = new QVBoxLayout(propertiesWidget);

//     QLabel* brightnessLabel = new QLabel("Brightness:");
//     brightnessSlider = new QSlider(Qt::Horizontal);
//     brightnessSlider->setRange(0, 100);
//     brightnessSlider->setValue(50);

//     QLabel* contrastLabel = new QLabel("Contrast:");
//     contrastSlider = new QSlider(Qt::Horizontal);
//     contrastSlider->setRange(10, 300);
//     contrastSlider->setValue(100);

//     processButton = new QPushButton("Process Image");

//     layout->addWidget(brightnessLabel);
//     layout->addWidget(brightnessSlider);
//     layout->addWidget(contrastLabel);
//     layout->addWidget(contrastSlider);
//     layout->addWidget(processButton);

//     propertiesPanel->setWidget(propertiesWidget);
//     addDockWidget(Qt::RightDockWidgetArea, propertiesPanel);

//     // Set up the menu bar
//     QMenu* fileMenu = menuBar()->addMenu("File");
//     QAction* openAction = fileMenu->addAction("Open Image");
//     QAction* saveAction = fileMenu->addAction("Save Image");
//     QAction* exitAction = fileMenu->addAction("Exit");

//     connect(exitAction, &QAction::triggered, this, &QMainWindow::close);

//     // Connect menu actions
//     connect(openAction, &QAction::triggered, this, &MainWindow::openImage);
//     connect(saveAction, &QAction::triggered, this, &MainWindow::saveImage);
//     connect(processButton, &QPushButton::clicked, this, &MainWindow::processImage);

//     // Connect sliders
//     connect(brightnessSlider, &QSlider::valueChanged, this, [this](int value) {
//         brightnessContrastNode->setBrightness(value);
//         brightnessContrastNode->setInput(inputNode->getImage());  // Re-set input
//         processImage();
//     });

//     connect(contrastSlider, &QSlider::valueChanged, this, [this](int value) {
//         double scaledContrast = static_cast<double>(value) / 100.0;
//         brightnessContrastNode->setContrast(scaledContrast);
//         brightnessContrastNode->setInput(inputNode->getImage());  // Re-set input
//         processImage();
//     });

//     connect(channelSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](int comboIndex) {
//         int selectedChannel = channelSelector->itemData(comboIndex).toInt();  // Get actual data: -1, 0, 1, 2

//         if (selectedChannel == -1) {
//             displayChannelImage(inputNode->getImage());  // Original
//         } else {
//             splitterNode->setChannelIndex(selectedChannel);
//             splitterNode->setInput(inputNode->getImage());
//             cv::Mat channelImage = splitterNode->process();
//             displayChannelImage(channelImage);
//         }
//     });

//     connect(blurRadiusSlider, &QSlider::valueChanged, this, [this](int value) {
//         blurNode->setRadius(value);  // Set blur radius in the node
//         processImage();  // Process the image after updating the radius
//     });

//     connect(blurTypeSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int index) {
//         BlurNode::BlurType blurType = (index == 0) ? BlurNode::BlurType::Uniform : BlurNode::BlurType::Directional;
//         blurNode->setBlurType(blurType);  // Set blur type
//         processImage();  // Process the image after updating the blur type
//     });
// }

// MainWindow::~MainWindow() {
//     delete inputNode;
//     delete brightnessContrastNode;
//     delete outputNode;
//     delete splitterNode;
//     delete channelSelector;
//     delete thresholdNode;
// }


// void MainWindow::displayChannelImage(const cv::Mat& image) {
//     if (image.empty()) {
//         qDebug() << "Trying to display empty image";
//         return;
//     }

//     cv::Mat displayMat;
//     if (image.channels() == 1) {
//         cv::cvtColor(image, displayMat, cv::COLOR_GRAY2RGB);
//     } else {
//         cv::cvtColor(image, displayMat, cv::COLOR_BGR2RGB);
//     }

//     QImage qimg(displayMat.data, displayMat.cols, displayMat.rows, displayMat.step, QImage::Format_RGB888);
//     scene->clear();  // Remove previous items
//     scene->addPixmap(QPixmap::fromImage(qimg));
//     view->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
// }


// void MainWindow::showKernelPreview() {
//     cv::Mat kernelPreview = blurNode->getKernelPreview();
//     cv::imshow("Kernel Preview", kernelPreview);
// }


// void MainWindow::openImage() {
//     try {
//         // Use a fixed path or open dialog
//         QString filePath = "C:/Users/_Astitva_Aryan_/OneDrive/Desktop/node-based-image-processor/sherry-christian-8Myh76_3M2U-unsplash.jpg";

//         std::cout << "File path: " << filePath.toStdString() << std::endl;

//         if (filePath.isEmpty()) {
//             throw std::runtime_error("No file selected.");
//         }

//         QFile file(filePath);
//         if (!file.exists()) {
//             std::cerr << "File does not exist!" << std::endl;
//             QMessageBox::critical(this, "Error", "File does not exist.");
//             return;
//         }

//         // Load image using OpenCV
//         cv::Mat image = cv::imread(filePath.toStdString());
//         if (image.empty()) {
//             std::cerr << "Failed to load image: " << filePath.toStdString() << std::endl;
//             QMessageBox::critical(this, "Error", "Failed to load the image.");
//             return;
//         }

//         std::cout << "Image dimensions: " << image.rows << " x " << image.cols << std::endl;
//         std::cout << "Channels: " << image.channels() << std::endl;

//         if (!image.isContinuous()) {
//             image = image.clone();
//         }

//         // Feed image into inputNode
//         inputNode->setImage(image);

//         // Pass the image through the pipeline (input → brightness/contrast)
//         brightnessContrastNode->setInput(inputNode->getImage());

//         // Show the processed image (with default brightness/contrast)
//         processImage();

//         QMessageBox::information(this, "Image Loaded", "Image loaded and processed successfully!");

//     } catch (const std::exception& e) {
//         QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
//     }
// }

// void MainWindow::saveImage() {
//     try {
//         QString filePath = QFileDialog::getSaveFileName(this, "Save Image", "", "Images (*.png *.jpg *.jpeg *.bmp)");
//         if (!filePath.isEmpty()) {
//             // Ensure the output directory exists
//             std::filesystem::path outputPath = std::filesystem::path(filePath.toStdString()).parent_path();
//             if (!std::filesystem::exists(outputPath)) {
//                 std::filesystem::create_directories(outputPath);
//             }

//             outputNode->setOutputPath(filePath.toStdString());
//             outputNode->process();
//             QMessageBox::information(this, "Image Saved", "Image saved successfully!");
//         }
//     } catch (const std::exception& e) {
//         QMessageBox::critical(this, "Error", e.what());
//     }
// }


// void MainWindow::processImage() {
//     // Disable UI interactions while processing
//     setEnabled(false);

//     // Run heavy processing in background
//     QtConcurrent::run([=]() {
//         try {
//             cv::Mat output = brightnessContrastNode->process();

//             if (splitterNode) {
//                 splitterNode->setInput(output);
//                 output = splitterNode->process();
//             }

//             if (blurNode) {
//                 // Downscale for smoother preview if image is too large
//                 cv::Mat previewInput;
//                 if (output.cols > 2000 || output.rows > 2000) {
//                     cv::resize(output, previewInput, cv::Size(), 0.25, 0.25);
//                 } else {
//                     previewInput = output;
//                 }

//                 blurNode->setInput(previewInput);
//                 cv::Mat blurredPreview = blurNode->process();

//                 // Resize back to original size if needed
//                 if (previewInput.size() != output.size()) {
//                     cv::resize(blurredPreview, output, output.size());
//                 } else {
//                     output = blurredPreview;
//                 }
//             }

//             // Convert for QImage display
//             cv::Mat rgbImage;
//             if (output.channels() == 3) {
//                 cv::cvtColor(output, rgbImage, cv::COLOR_BGR2RGB);
//             } else {
//                 cv::cvtColor(output, rgbImage, cv::COLOR_GRAY2RGB);
//             }

//             QImage qimg(rgbImage.data, rgbImage.cols, rgbImage.rows, rgbImage.step, QImage::Format_RGB888);
//             QPixmap pixmap = QPixmap::fromImage(qimg.copy());

//             // Post result to GUI thread
//             QMetaObject::invokeMethod(this, [=]() {
//                 scene->clear();
//                 QGraphicsPixmapItem* item = scene->addPixmap(pixmap);
//                 item->setTransformationMode(Qt::SmoothTransformation);
//                 view->resetTransform();
//                 view->fitInView(item, Qt::KeepAspectRatio);

//                 setEnabled(true);  // Re-enable UI
//             });

//         } catch (const std::exception& e) {
//             QMetaObject::invokeMethod(this, [=]() {
//                 QMessageBox::critical(this, "Error", e.what());
//                 setEnabled(true);
//             });
//         }
//     });
// }


#include "MainWindow.hpp"
#include <filesystem>
#include <QComboBox>
#include <QThread>
#include <QImage>
#include <QPixmap>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QtConcurrent/QtConcurrent>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    inputNode(new ImageInputNode("")),
    brightnessContrastNode(new BrightnessContrastNode(50, 1.5)),
    splitterNode(new ColorChannelSplitterNode()),
    outputNode(new OutputNode()),
    blurNode(new BlurNode()){
   // thresholdNode(new ThresholdNode()) {

    // Create a central widget and layout for the full view
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* centralLayout = new QVBoxLayout(centralWidget);

    // Set up the canvas (view)
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);
    centralLayout->addWidget(view);  // Add view to the layout

    // Channel selector (ComboBox) setup
    channelSelector = new QComboBox(this);
    channelSelector->addItem("Original Color Image", -1);
    channelSelector->addItem("Blue Channel", 0);   // Blue channel = index 0
    channelSelector->addItem("Red Channel", 2);    // Red channel = index 1
    channelSelector->addItem("Green Channel", 1);  // Green channel = index 2
    centralLayout->addWidget(channelSelector);

    // **Blur Node Controls**
    QLabel* blurLabel = new QLabel("Blur Radius:");
    blurRadiusSlider = new QSlider(Qt::Horizontal);
    blurRadiusSlider->setRange(1, 20);
    blurRadiusSlider->setValue(5);

    QLabel* blurTypeLabel = new QLabel("Blur Type:");
    blurTypeSelector = new QComboBox(this);
    blurTypeSelector->addItem("Uniform");
    blurTypeSelector->addItem("Directional");

    centralLayout->addWidget(blurLabel);
    centralLayout->addWidget(blurRadiusSlider);
    centralLayout->addWidget(blurTypeLabel);
    centralLayout->addWidget(blurTypeSelector);

    // // **Threshold Node Controls**
    // QLabel* thresholdLabel = new QLabel("Threshold Value:");
    // thresholdSlider = new QSlider(Qt::Horizontal);
    // thresholdSlider->setRange(0, 255);
    // thresholdSlider->setValue(128);  // Default threshold value

    // centralLayout->addWidget(thresholdLabel);
    // centralLayout->addWidget(thresholdSlider);

    // Set the final layout to central widget
    centralWidget->setLayout(centralLayout);
    setCentralWidget(centralWidget);

    // Add a sample node to the canvas
    QGraphicsRectItem* node = scene->addRect(0, 0, 100, 50);
    node->setFlag(QGraphicsItem::ItemIsMovable);

    // Set up the properties panel
    propertiesPanel = new QDockWidget("Properties", this);
    QWidget* propertiesWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(propertiesWidget);

    QLabel* brightnessLabel = new QLabel("Brightness:");
    brightnessSlider = new QSlider(Qt::Horizontal);
    brightnessSlider->setRange(0, 100);
    brightnessSlider->setValue(50);

    QLabel* contrastLabel = new QLabel("Contrast:");
    contrastSlider = new QSlider(Qt::Horizontal);
    contrastSlider->setRange(10, 300);
    contrastSlider->setValue(100);

    processButton = new QPushButton("Process Image");

    layout->addWidget(brightnessLabel);
    layout->addWidget(brightnessSlider);
    layout->addWidget(contrastLabel);
    layout->addWidget(contrastSlider);
    layout->addWidget(processButton);

    propertiesPanel->setWidget(propertiesWidget);
    addDockWidget(Qt::RightDockWidgetArea, propertiesPanel);

    // Set up the menu bar
    QMenu* fileMenu = menuBar()->addMenu("File");
    QAction* openAction = fileMenu->addAction("Open Image");
    QAction* saveAction = fileMenu->addAction("Save Image");
    QAction* exitAction = fileMenu->addAction("Exit");

    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);

    // Connect menu actions
    connect(openAction, &QAction::triggered, this, &MainWindow::openImage);
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveImage);
    connect(processButton, &QPushButton::clicked, this, &MainWindow::processImage);

    // Connect sliders for brightness, contrast, and threshold
    connect(brightnessSlider, &QSlider::valueChanged, this, [this](int value) {
        brightnessContrastNode->setBrightness(value);
        brightnessContrastNode->setInput(inputNode->getImage());  // Re-set input
        processImage();
    });

    connect(contrastSlider, &QSlider::valueChanged, this, [this](int value) {
        double scaledContrast = static_cast<double>(value) / 100.0;
        brightnessContrastNode->setContrast(scaledContrast);
        brightnessContrastNode->setInput(inputNode->getImage());  // Re-set input
        processImage();
    });

    // connect(thresholdSlider, &QSlider::valueChanged, this, [this](int value) {
    //     thresholdNode->setThresholdValue(value);
    //     thresholdNode->setInput(inputNode->getImage());  // Re-set input
    //     processImage();
    // });

    connect(channelSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](int comboIndex) {
        int selectedChannel = channelSelector->itemData(comboIndex).toInt();  // Get actual data: -1, 0, 1, 2

        if (selectedChannel == -1) {
            displayChannelImage(inputNode->getImage());  // Original
        } else {
            splitterNode->setChannelIndex(selectedChannel);
            splitterNode->setInput(inputNode->getImage());
            cv::Mat channelImage = splitterNode->process();
            displayChannelImage(channelImage);
        }
    });

    connect(blurRadiusSlider, &QSlider::valueChanged, this, [this](int value) {
        blurNode->setRadius(value);  // Set blur radius in the node
        processImage();  // Process the image after updating the radius
    });

    connect(blurTypeSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int index) {
        BlurNode::BlurType blurType = (index == 0) ? BlurNode::BlurType::Uniform : BlurNode::BlurType::Directional;
        blurNode->setBlurType(blurType);  // Set blur type
        processImage();  // Process the image after updating the blur type
    });
}

MainWindow::~MainWindow() {
    delete inputNode;
    delete brightnessContrastNode;
    delete outputNode;
    delete splitterNode;
    delete channelSelector;
   // delete thresholdNode;
}

void MainWindow::displayChannelImage(const cv::Mat& image) {
    if (image.empty()) {
        qDebug() << "Trying to display empty image";
        return;
    }

    cv::Mat displayMat;
    if (image.channels() == 1) {
        cv::cvtColor(image, displayMat, cv::COLOR_GRAY2RGB);
    } else {
        cv::cvtColor(image, displayMat, cv::COLOR_BGR2RGB);
    }

    QImage qimg(displayMat.data, displayMat.cols, displayMat.rows, displayMat.step, QImage::Format_RGB888);
    scene->clear();  // Remove previous items
    scene->addPixmap(QPixmap::fromImage(qimg));
    view->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}


void MainWindow::showKernelPreview() {
    cv::Mat kernelPreview = blurNode->getKernelPreview();
    cv::imshow("Kernel Preview", kernelPreview);
}


void MainWindow::openImage() {
    try {
        QString filePath = "C:/Users/_Astitva_Aryan_/OneDrive/Desktop/node-based-image-processor/sherry-christian-8Myh76_3M2U-unsplash.jpg";

        if (filePath.isEmpty()) {
            throw std::runtime_error("No file selected.");
        }

        QFile file(filePath);
        if (!file.exists()) {
            std::cerr << "File does not exist!" << std::endl;
            QMessageBox::critical(this, "Error", "File does not exist.");
            return;
        }

        cv::Mat image = cv::imread(filePath.toStdString());
        if (image.empty()) {
            std::cerr << "Failed to load image: " << filePath.toStdString() << std::endl;
            QMessageBox::critical(this, "Error", "Failed to load the image.");
            return;
        }

        inputNode->setImage(image);

        brightnessContrastNode->setInput(inputNode->getImage());
        processImage();

        QMessageBox::information(this, "Image Loaded", "Image loaded and processed successfully!");

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
    }
}

void MainWindow::saveImage() {
    try {
        QString filePath = QFileDialog::getSaveFileName(this, "Save Image", "", "Images (*.png *.jpg *.jpeg *.bmp)");
        if (!filePath.isEmpty()) {
            std::filesystem::path outputPath = std::filesystem::path(filePath.toStdString()).parent_path();
            if (!std::filesystem::exists(outputPath)) {
                std::filesystem::create_directories(outputPath);
            }

            outputNode->setOutputPath(filePath.toStdString());
            outputNode->process();
            QMessageBox::information(this, "Image Saved", "Image saved successfully!");
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
    }
}

void MainWindow::processImage() {
    // Disable UI interactions while processing
    setEnabled(false);

    // Run heavy processing in the background
    QtConcurrent::run([=]() {
        try {
            // Step 1: Apply brightness and contrast adjustments
            cv::Mat output = brightnessContrastNode->process();

            // Step 2: Apply splitter node if it exists
            if (splitterNode) {
                splitterNode->setInput(output);
                output = splitterNode->process();
            }

            // Step 3: Apply blur effect if blur node exists
            if (blurNode) {
                // Downscale for smoother preview if image is too large
                cv::Mat previewInput;
                if (output.cols > 2000 || output.rows > 2000) {
                    cv::resize(output, previewInput, cv::Size(), 0.25, 0.25);
                } else {
                    previewInput = output;
                }

                blurNode->setInput(previewInput);
                cv::Mat blurredPreview = blurNode->process();

                // Resize back to original size if needed
                if (previewInput.size() != output.size()) {
                    cv::resize(blurredPreview, output, output.size());
                } else {
                    output = blurredPreview;
                }
            }

            // // Step 4: Apply threshold effect if threshold node exists
            // if (thresholdNode) {
            //     thresholdNode->setInput(output);
            //     output = thresholdNode->process();
            // }

            // Step 5: Convert processed image for QImage display
            cv::Mat rgbImage;
            if (output.channels() == 3) {
                cv::cvtColor(output, rgbImage, cv::COLOR_BGR2RGB);
            } else {
                cv::cvtColor(output, rgbImage, cv::COLOR_GRAY2RGB);
            }

            // Step 6: Create QImage for displaying in QGraphicsView
            QImage qimg(rgbImage.data, rgbImage.cols, rgbImage.rows, rgbImage.step, QImage::Format_RGB888);
            QPixmap pixmap = QPixmap::fromImage(qimg.copy());

            // Step 7: Post result to GUI thread
            QMetaObject::invokeMethod(this, [=]() {
                scene->clear();
                QGraphicsPixmapItem* item = scene->addPixmap(pixmap);
                item->setTransformationMode(Qt::SmoothTransformation);
                view->resetTransform();
                view->fitInView(item, Qt::KeepAspectRatio);

                setEnabled(true);  // Re-enable UI
            });

        } catch (const std::exception& e) {
            // Handle exceptions and display error messages
            QMetaObject::invokeMethod(this, [=]() {
                QMessageBox::critical(this, "Error", e.what());
                setEnabled(true);
            });
        }
    });
}


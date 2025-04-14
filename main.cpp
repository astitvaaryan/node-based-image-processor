#include <QApplication>
#include "MainWindow.hpp"  // Include MainWindow.hpp

int main(int argc, char* argv[]) {
    cv::setNumThreads(1);
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("Node-Based Image Processor");
    window.resize(800, 600);
    window.show();

    return app.exec();
}

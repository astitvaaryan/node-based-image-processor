# Node-Based Image Processor

A Qt-based application for building and executing image processing workflows using a **node graph interface**. Each operation (grayscale, edge detection, etc.) is a node that connects to others, forming a pipeline. The system ensures correct execution order, detects circular dependencies, and caches results to avoid unnecessary recomputation.

---

## 🚀 Project Overview

This project allows users to:
- Construct image processing pipelines visually
- Evaluate processing graphs using topological sorting
- Avoid recomputation with intelligent result caching
- Experiment with modular image transformations

Useful for prototyping, educational demonstrations, and building extensible visual processing tools.

---

## ✨ Features Implemented

- 🔧 **Drag-and-drop node graph interface** using `QGraphicsProxyWidget`
- 📸 **Image processing nodes**: grayscale, Gaussian blur, edge detection, thresholding
- 🧠 **Dependency graph evaluation** with cycle detection
- ⚡ **Caching system**: processes only changed nodes
- 🔁 **Real-time visual feedback** of node outputs
- 🧱 Easily extensible for adding new node types

---

## 🛠️ Build Instructions

### 📦 Prerequisites
- Qt 5 or Qt 6 (tested with Qt 5.15+)
- C++17 compatible compiler
- CMake (recommended)
- OpenCV (for image operations)


## 🔧 Future Improvements

- 💾 **Save/Load Graphs to/from JSON**  
  Allow users to export their node pipeline and reload it later for continued editing.

- 🧠 **Graph Architecture Visualization Enhancements**  
  Improve the layout and aesthetics of the graph-based interface using automatic node arrangement and zoom/pan capabilities.

- 🔗 **Edge Rendering & Connection Logic**  
  Enhance visual connections between nodes with curved edges, interactive linking, and real-time visual feedback on valid/invalid connections.

- 🧩 **Add More Node Types**  
  Expand available operations (e.g., sharpening, dilation, morphological transformations, contrast adjustment).

- 🛠️ **User-Defined Custom Nodes**  
  Allow users to define and register their own image processing functions via a scripting interface or plugin system.

- 🔌 **Plugin-Based Architecture**  
  Modularize node creation and allow external plugins to contribute new node types or processing engines.


### 🧑‍💻 Clone the repo
```bash
git clone https://github.com/astitvaaryan/node-based-image-processor.git
cd node-based-image-processor



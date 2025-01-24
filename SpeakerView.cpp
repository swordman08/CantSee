#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "MonoStack.h" 
#include <stdexcept>
#include "SpeakerView.h"

    SpeakerView::SpeakerView(const std::string& filename) {
        // Implement file reading here
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("File cannot be opened");
        }

        std::string line;
        rows = 0;
        cols = -1;
        //cols = -1 for easy error checking, meaning theres 0 coloumns, as coloumn one in an array will be cols = 0.
        while (getline(file, line)) {
            if (cols == -1) {
                std::stringstream ss(line);
                double temp;
                while (ss >> temp) ++cols;
            }
            ++rows;
        }

        // Allocate memory for heights
        heights = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            heights[i] = new double[cols];
        }

        // Reset file to beginning and read heights
        file.clear();
        file.seekg(0);
        int row = 0;
        while (getline(file, line)) {
            std::stringstream ss(line);
            for (int col = 0; col <= cols; ++col) {
                ss >> heights[row][col];
            }
            ++row;
        }
    }

    SpeakerView::~SpeakerView() {
        // Implement memory deallocation for heights
        for (int i = 0; i < rows; ++i) {
            delete[] heights[i];
        }
        delete[] heights;
    }

    void SpeakerView::analyzeView() {
        for (int col = 0; col <= cols; ++col) {
            MonoStack<double> stack(rows, 'd');
            for (int row = 0; row < rows; ++row) {
                stack.push(heights[row][col]);
            }
            std::cout << "Column " << col << ": " << stack.size() << " can see the speaker. Heights: ";
            while (!stack.isEmpty()) {
                std::cout << stack.pop() << " ";
            }
            std::cout << std::endl;
        }
    }

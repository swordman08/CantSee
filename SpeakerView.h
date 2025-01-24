#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H
#include <string>
#include "MonoStack.h" // Include the MonoStack header

class SpeakerView {
private:
    double** heights; // dynamic allocation for a 2D array
    int rows;
    int cols;

public:
    // Constructor Takes a filename to load the seat heights from
    SpeakerView(const std::string& filename);
    
    // Destructor Cleans up dynamically allocated memory
    ~SpeakerView();

    // Analyze and print the view from each column
    void analyzeView();
};

#endif // SPEAKERVIEW_H

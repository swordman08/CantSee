#include <stdexcept>
#include "SpeakerView.h"
#include <iostream>
#include <fstream>


    int main(int argc, char* argv[]) {
    std::string filename = "input.txt";
    // Check if a filename has been provided
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    std::string inputString(argv[1]);
    try {
        // Create an instance of SpeakerView using command lind arguement.
        SpeakerView view(inputString);

        // Analyze the view and print the results
        view.analyzeView();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

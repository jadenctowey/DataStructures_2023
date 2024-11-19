/*
It should only contain a main method. Your main method should do the following:
    - Instantiate a FileProcessor
    - Translate the provided input file to Rövarspråket using the file processor.
    - Exit
*/

// #include "Model.h" // Include model header 
// #include "Translator.h" // Include translator header 
// #include "FileProcessor.h" // Include fileProcessor header 


// int main() {


// //From FileProcessor
//     FileProcessor fileProc;
//     std:: string inputFile = "original.txt";
//     std:: string outputFile = "Robbers.html";
//     fileProc.processFile(inputFile, outputFile);
//     return 0;   //show if the program completed
// }

#include <iostream>
#include "FileProcessor.h"
using namespace std;


int main() {
    FileProcessor processor;

    // Replace these filenames with the actual input and output filenames
    string inputFile = "original.txt";
    string outputFile = "Robbers.html";

    // Process the file
    processor.processFile(inputFile, outputFile);

    cout << "File processed successfully." << endl;

    return 0;
}

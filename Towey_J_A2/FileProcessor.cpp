/*
You will build a class named FileProcessor that will take txt files containing English text 
and produce a html file containing the equivalent Rövarspråket translation that can be viewed 
in a standard web browser. The class will contain the following public methods:
    - A default constructor
    - A default destructor
    - processFile – takes a string representing the input file (English) and a string representing the 
    output file (where the Rövarspråket translation will be written). This method has a void return type. 
    The method should produce a html file that has the original English text in **bold** followed by an 
    empty line, followed by the Rövarspråket translation in *italics*.
*/

#include <iostream>
#include <fstream>              //fstream and sstream for entering files
#include <sstream>          
#include <string>
#include "Translator.h"          // Include translator header 
#include "FileProcessor.h"
using namespace std;


FileProcessor::FileProcessor() {
}


void FileProcessor::processFile(const string& inputString, const string& fileName){
        Translator t;
        ifstream readMyFile(inputString);

        string line;
        
    originalText.clear();
    translatedText.clear();

        while (getline(readMyFile, line)) {
            originalText += "<p><b>" + line + "</b><br></p>\n";
            translatedText += "<p><i>" + t.translateEnglishSentence(line) + "</i><br></p>\n";
    }

    ofstream output(fileName);
    originalText += "<p><b></b><br></p>";
    translatedText += "<p><i></i><br></p>";

    if (output.is_open()){
    output << "<!DOCTYPE html>\n<html>\n<head>\n<title>English to Robber Translation</title>\n</head>\n<body>\n";
    output << originalText;
    output <<  translatedText;
    output << "</body>\n</html>";
    output.close();
    }
};
FileProcessor::~FileProcessor() {
}




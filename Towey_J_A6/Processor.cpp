#include "Processor.h"

// constructor
Processor::Processor(){
}

// destructor
Processor::~Processor(){
}

// gets the size of the adjacency matrix
int Processor::getSize(std::string inputFile){
    std::fstream filer;
    filer.open(inputFile);
    std::string sizeString;
    while (getline(filer, sizeString)){
        graphSize = std::stoi(sizeString);
        break;
    }
    filer.close();
    return graphSize;
}

// takes in a text file and reads the file into a string and converts
void Processor::processFiles(std::string inputFile, double** doubleArr){
    std::fstream filer;
    std::string matrix = "";
    std::string line;

    filer.open(inputFile);
    int count = 0;

    while (getline(filer, line)){
        if (count == 0){
            count++;
            continue;
        }
        if (line == "END"){
            break;
        }
        matrix += line += "\n";
    }

    for (int i = 0; i < graphSize; ++i){
        doubleArr[i] = new double[graphSize];
    }

    int row = 0, column = 0;
    std::string temp = "";

    for (int i = 0; i < matrix.length(); ++i){
        if (matrix[i] == ' ' || matrix[i] == '\n' || matrix[i] == '\r'){
            if (!temp.empty()){
                doubleArr[row][column++] = std::stod(temp);
                temp = "";
            }
            if (matrix[i] == '\n' || matrix[i] == '\r'){
            row++;
            column = 0;
            }
        } else {
            temp += matrix[i];
        }
    }

    std::cout << std::setprecision(1);
    std::cout << std::fixed;
}
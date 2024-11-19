#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <fstream>
#include <iostream>
#include <iomanip>

class Processor {
    public:
        Processor();
        ~Processor();
        int getSize(std::string inputFile);
        void processFiles(std::string inputFile, double** doubleArr);
        int graphSize;
};
#endif
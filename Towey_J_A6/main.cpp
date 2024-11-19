#include "WGraph.h"
#include "Processor.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){

    Processor filer;
    int graphSize = filer.getSize(argv[1]);
    double** doubleArr = new double*[graphSize];
    filer.processFiles(argv[1], doubleArr);

// Creates graph of edges from double** array 
    WGraph graph(graphSize);
    for (unsigned int i = 0; i < graphSize; ++i) {
        for (unsigned int j = 0; j < graphSize; ++j) {
            if (doubleArr[i][j] != 0) {
                graph.addEdge(i, j, doubleArr[i][j]);
            }
        }
    }

// computes MST
    graph.computeMST();
    return 0;
}
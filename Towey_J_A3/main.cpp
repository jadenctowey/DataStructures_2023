#include "MonoStack.h"
#include "SpeakerView.h"
#include <iostream>

int main(int argc, char *argv[]){
    std::string inputFileName = argv[1];
    SpeakerView* sp = new SpeakerView(inputFileName);
    sp->printStacks();
    
    return 0;
}
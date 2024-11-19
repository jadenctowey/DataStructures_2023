#ifndef SPEAKER_VIEW_H
#define SPEAKER_VIEW_H

#include <iostream> //input/ output 
#include "MonoStack.h" //connect the other file 

//template <typename T>
class SpeakerView{
    public: 
        SpeakerView(std::string inputFileName);
        ~SpeakerView();
        std::string fileToString();
        float** stringToArray();
        int getRows();
        int getCols();
        float getFloat();
        void printArray();
        void printStacks();
        MonoStack<float> processSeats(int column);
    private: 
        std::string fileName;
        std::string m_convertedString;
        MonoStack<float> *m_stackCollection;
        float** m_seat_array;
        int m_rows;
        int m_cols;
        int m_charIndex;
};

#endif

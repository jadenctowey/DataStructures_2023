#include <iostream> //input/ output 
#include <fstream>  //use input files
#include "SpeakerView.h"   //include both other files 
#include "MonoStack.h"
#include <string>           //work w strings 

SpeakerView::SpeakerView(std::string inputFileName){        //constructor
    fileName = inputFileName;
    m_convertedString = fileToString();
    m_rows = getRows();
    m_cols = getCols();
    m_charIndex = 0;    
    stringToArray();
}
 
SpeakerView::~SpeakerView(){
        //nothing needed in deconstructor 
}

std::string SpeakerView::fileToString(){
    std::string line;                 //  store lines 
    std::string convertedString;        //store text 
    std::ifstream file(fileName);       //opens file
    int count = 0;        //count variables as u go (to stop)
    if(file.is_open()){
        while((getline(file, line))&&(count < getRows())){   //read until done
            if (++count != 1){              
                convertedString += line;        //add to bif text (stack)
                convertedString += "\n";
            }
        }
    }
    convertedString += line;        //adds last line
    convertedString += 'x';         //adds x
    return convertedString;         //spacing
}

int SpeakerView::getRows(){
    std::ifstream file(fileName);
    std::string line;       //store lines
    int numRows = 0;        //start 0
    while(getline(file, line)){   
        numRows += 1;       //keep track of rows counted 
    }
    return numRows -2;      //get rid of begin and end
}

int SpeakerView::getCols(){
    int i = 0;          //start 0
    int numCols = 0;        //counting columns by spaces 
    while (m_convertedString[i]!= '\n'){
        i++;                //keep moving through 
        if (m_convertedString[i] == ' '){       //if there is a space then add to coloumn
            numCols++;
        }
    }
    numCols++;      
    return numCols;
}

float SpeakerView::getFloat(){
    std::string stringToFloat = "";
    while (true){
        if (((m_convertedString[m_charIndex] == ' ')||(m_convertedString[m_charIndex] == '\n')) || (m_convertedString[m_charIndex] == 'x')) {
            m_charIndex ++;
            return std::stof(stringToFloat);
        } else {
            stringToFloat += m_convertedString[m_charIndex];
            m_charIndex ++;
        }
    }
}

float** SpeakerView::stringToArray(){           //make float so it doesnt confuse column stuff
    m_seat_array = new float*[m_rows];
    for(int i=0; i<m_rows; i++) {
        m_seat_array[i] = new float[m_cols];
    }
    for (int i=0; i<m_rows; i++){
        for (int j=0; j<m_cols; j++){
            m_seat_array[i][j] = getFloat();
        }
    }
    return m_seat_array;
}

void SpeakerView::printArray(){
    for(int i=0; i<m_rows; i++){            //each row 
        for(int j=0; j<m_cols; j++){        //each col
            std::cout<<m_seat_array[i][j]<<' '; //print the values 
        }
        std::cout<<"\n";
    }
}

/* unable to understand well
    source: Sami Hammoud ************
*/

MonoStack<float> SpeakerView::processSeats(int column){
    MonoStack<float> *myStack = new MonoStack<float>(1);
    for(int i=m_rows-1; i>=0; i--){
        myStack->push(m_seat_array[i][column]);
    }
    return *myStack;
}

void SpeakerView::printStacks(){
    for (int i=0; i<m_cols; i++){
        std::cout<<"There are "<<processSeats(i).size()<<" people that can see in column " << i << ". Their heights are are: ";
        processSeats(i).printS();
    }
}

/* unable to understand well
    source: Sami Hammoud ***************
*/
#include <iostream>
#include <fstream>
#include <string>
#include "PalindromeFinder.h"
#include "DNASeq.h"
#include "DblList.h"

//constructor 
PalindromeFinder::PalindromeFinder(std::string inputFile){
    myFile = inputFile;
}

//deconstructor 
PalindromeFinder::~PalindromeFinder(){
    //nothing
}

//func. reads files and seperates and organizes rows and seq. 
DNASeq** PalindromeFinder::getArrayOfDNA(){
    int numRows = getRows();                    //find how many rows (sequences) to read
    DNASeq** arr = new DNASeq*[numRows];
    std::ifstream file(myFile);                 //opens the file 
    if (file.is_open()) {                   //if open then...
        std::string line;
        int count = 0;
        while (count < numRows && getline(file, line)) {    //while there r the lines to read and store in line
            arr[count] = new DNASeq(line);              //create new DNASeq for all lines
            count++;                            //tracks DNA sequences 
        }
        file.close(); // close file when done going thru
    }
    return arr;     //return full array (POINTERS TO SEQ)
}

//func. to find substrings inside the file and sequence and say if palindrome 
void PalindromeFinder::findSubstrings(DNASeq** arr) {
    for (int i = 0; i < getRows() - 1; i++) {       //goes through each sequence 
        if (arr[i]->isGeneticPalindrome()) {       //check if palindrome 
            std::cout << arr[i]->getDNA() << " - Genetic Palindrome\n";        //print when it is
        } else {                                                                //if not one... 
            std::cout << arr[i]->getDNA() << " - Not a Genetic Palindrome\n";          //...print not one
        }
        std::string dnaString = arr[i]->getDNA();
        for (int j = 0; j < dnaString.size() - 4; j++) {            //try to find palindrome substrings
            for (int c = j + 5; c < dnaString.size(); c++) {            //make a substring andh check for all options
                DNASeq* substring = new DNASeq(dnaString.substr(j, c - j));
                if (substring->isGeneticPalindrome()) {                         //if it ends up having a palindrome substring
                    std::cout << substring->getDNA() << " is a Substring Palindrome\n";     //print 
                }
            }
        }
    }
}

//func. 
int PalindromeFinder::getRows() {
    std::ifstream file(myFile);
    std::string line;
    int numRows = 0;
    if (file.is_open()) {               //if succesfully opened 
        while (getline(file, line)) {       //count and read all lines
            numRows++;          //add
        }
        file.close(); // Close the file when done
    }
    return numRows;         //returns how many lines in file 
}

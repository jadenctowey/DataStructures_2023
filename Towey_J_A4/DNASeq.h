#ifndef DNA_SEQ_H
#define DNA_SEQ_H
#include <iostream>
#include "DblList.h"


class DNASeq{
    public: 
        DNASeq();
        ~DNASeq();
        DNASeq(std::string charString);
        DNASeq(DblList<char> list);
        void createDNA(std::string charString);
        DblList<char> switchLetter();
        void printList(DblList<char> inputList);
        DblList<char> substring(int s, int e);
        DblList<char> reverseSwitch();
        bool isGeneticPalindrome();
        void printDNA();
       DblList<char> getDNA();          //for palindrome finder 

    private: 
        std::string fileName;
        DblList<char> mySeq;
        std::string data;


};
#endif



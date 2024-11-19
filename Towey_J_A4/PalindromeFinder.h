#ifndef PALINDROME_FINDER_H
#define PALINDROME_FINDER_H

#include <iostream>
#include <list>
#include "DblList.h"
#include "DNASeq.h"

class PalindromeFinder : public DNASeq {
    public:
        PalindromeFinder(std::string inputFileName);
        ~PalindromeFinder();
        DNASeq **getArrayOfDNA();
        void findSubstrings(DNASeq** arr);
        int getRows();

    private:
        DblList<char> reverseSwitch;
        DblList<char> data;
        std::string myFile;
};

#endif

/*
class PalindromeFinder : public DNASeq {
    public:
   
        PalindromeFinder(std::string inputFileName);
    
        //PalindromeFinder(DNASeq& DNA);
        DNASeq **getArrayOfDNA();
        int getRows();
        void findSubstrings(DNASeq** arr);


    private:
        DblList<char> m_reverseComplement;
        DblList<char> data;
        std::string myFile;
       

};
*/
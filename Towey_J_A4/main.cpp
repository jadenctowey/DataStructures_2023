#include <iostream>
#include <string>
#include "DNASeq.h"
#include "DblList.h"
#include "PalindromeFinder.h"


int main(int argc, char *argv[]){
    std::string inputFileName = argv[1];
    PalindromeFinder* pf = new PalindromeFinder(inputFileName);
    pf->findSubstrings(pf->getArrayOfDNA());
}
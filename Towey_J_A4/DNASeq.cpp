#include <iostream> 
#include <fstream> 
#include <string>
#include "DNASeq.h"
#include "DblList.h"

//constructor
DNASeq::DNASeq(){
    //nothing 
}

//deconstructor 
DNASeq::~DNASeq(){
    //nothing
}

//overloaded 
DNASeq::DNASeq(std::string charString){
    createDNA(charString);                  //creates the string
}
 
//overloaded
DNASeq::DNASeq(DblList<char> list){
    mySeq = list;                       //copy data from list to mySeq
}

//func. to create the string of characters 
void DNASeq::createDNA(std::string charString){
   for (int i=0; i<charString.size(); i++){         //iterate through 
        mySeq.addBack(charString[i]);               //add characters to array
    }
}

//func. to make a new list with opposite nucleotides
DblList<char> DNASeq::switchLetter(){
    DblList<char> switchLetterList;
    for(int i = 0; i < mySeq.size(); ++i){      //iterate through the sequence 
        switch (mySeq.get(i)) {
            case 'A':                           //for every A....
                switchLetterList.addBack('T');      //...replace it w T
                break;
            case 'C':                           //for every C....
                switchLetterList.addBack('G');      //...replace it w G
                break;
            case 'T':                           //for every T....
                switchLetterList.addBack('A');      //...replace it w A
                break;
            case 'G':                           //for every G....
                switchLetterList.addBack('C');      //...replace it w C
                 break;
            default:
                break;
        }
    }
    return switchLetterList;            //returns new opposite list 
}

//func. to print the new sequence 
void DNASeq::printList(DblList<char> inputList){
    for(int i = 0; i < inputList.size(); i++){         //iterate through all of new list
        std::cout << inputList.get(i);                  //print each element 
    }
}

//func. to create a substring between 2 points 
DblList<char> DNASeq::substring(int s, int e){      //s = start, e = end
    DblList<char> substring;        //create place to store substring
    for (int i=s; i<e; i++){            //iterate through list 
        substring.addBack(mySeq.get(i));        //add char to substring until range ends
    }
    return substring;           //returns characters from the original DNA seq. 
}

//func. to reverse the order of the list (back to front)
DblList<char> DNASeq::reverseSwitch(){
    DblList<char> switchLetterList = switchLetter();        //call switchLetter
    DblList<char> reverseSwitchList;                //create new place to store new list
    for(int i = 0; i < switchLetterList.size(); ++i){       //iterate...
        reverseSwitchList.addFront(switchLetterList.get(i));        //add from the list to new list
    }
    return reverseSwitchList;       //returns the reversed list 
}

//func to check the new string we edited to the og string
bool DNASeq::isGeneticPalindrome(){
    for(int i = 0; i < reverseSwitch().size(); i++){        //iterate through the reversed switched letters
        if (reverseSwitch().get(i) == mySeq.get(i)){        //compare character by chacter from new to og
        } else {
            return false;                     //if it breaks and soething doesn't match it is false
        }
    }
    return true;                     //completes... then is a palindrome 
}

//print the original sequence back out 
void DNASeq::printDNA() {
    for(int i = 0; i < mySeq.size(); i++){      //iterate 
        std::cout << mySeq.get(i);              //print each char 
    }
}

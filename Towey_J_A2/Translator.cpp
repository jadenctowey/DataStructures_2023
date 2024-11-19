/*
You will build a class named Translator that will translate English sentences
to Rövarspråket sentences using the Model class. The class will contain the following public methods:
    - A default constructor
    - A default destructor
    - translateEnglishWord – takes a single string representing a single English word as 
    input and returns a string representing the Rövarspråket translation.
    - translateEnglishSentence – takes a single string representing a single English 
    sentence as input and returns a string representing the Rövarspråket translation. Make sure to account for punctuation.
*/

#include "Model.h"          // Include model header 
#include "Translator.h"
#include <iostream>         //input and output 
using namespace std;
#include <string>          //working with strings 
#include <cstring>          // checks if in alphabet 

Translator::Translator() {
}


          //variables to store info i need
    string translate;
    Model model;        //use this to refer to Model.cpp



    string Translator::translateEnglishWord(const string& word){      //constant reference to a C++ string and the parameter is named word
        string translatedWord;
        for (char c : word){
            if (isalpha(c)){                //will only do it to alphabet letters
                if (model.isConsonant(c)){  //if it isConstant from model file
                    model.translateSingleConsonant(c, translatedWord);   //use method made in model file
                } else if (model.isVowel(c)){           //same as Consonant but w/ vowels
                    model.translateSingleVowel(c, translatedWord);
                }
            } else{
                translatedWord += c;         //leave the rest of the characters
            }
        }
        return translatedWord;
    };


    string Translator::translateEnglishSentence( const string& sentence){      //parameter sentence 
        string translatedSentence; 
        for (char c : sentence){
            if (isalpha(c)){                //will only do it to alphabet letters
                if (model.isConsonant(c)){  //if it isConstant from model file
                    model.translateSingleConsonant(c, translatedSentence);   //use method made in model file
                } else if (model.isVowel(c)){           //same as Consonant but w/ vowels
                    model.translateSingleVowel(c, translatedSentence);
                }
            } else{
                translatedSentence += c;         //leave the rest of the characters
            }
        }
        return translatedSentence;
    };




Translator::~Translator() {
    // Destructor implementation, if any
}

/*
looked up why i was getting a warning and this is the info i got 

The error message you're seeing is not actually an error; it's a warning. 
The warning message indicates that you're using a C++11 feature, which is 
the range-based for loop, but it seems like your compiler is set to use an earlier C++ standard.

so to compile i must enter ... 
g++ -std=c++11 *.cpp -o Translator.exe
*/
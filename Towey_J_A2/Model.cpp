/*
You will build a class named Model that will encode the rules of the Robber language. 
The class will contain the following public methods:
    - A default constructor
    - A default destructor
    - translateSingleConsonant– takes a single consonant character as input and returns
     a string representing its encoding in Rövarspråket. Capitalization should be preserved.
    - translateSingleVowel – takes a single vowel character as input and returns a 
    string representing its encoding in Rövarspråket. Capitalization should be preserved.
*/

#include <iostream>         //input and output 
using namespace std;
#include <string>          //working with strings 
#include "Model.h"

Model::Model() {
}
    string translatedText;
    char c;


    bool Model::isConsonant(char c){       //return true if consonant and false if not
        return !(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' ||
        c == 'o' || c == 'O' || c == 'u' || c == 'U');
        }

    void Model::translateSingleConsonant(char c, string& translatedText) {     
        if (isConsonant(c)){
            if (isupper(c)){                //learned how to do upper case lower case check with chatGPT --> lines identified 
                translatedText += c;
                translatedText += 'O';
                translatedText += c;
                translatedText += tolower(c);       //chatGPT
            } else{
                translatedText += c;
                translatedText += 'o';
                translatedText += c;
            }
        } else {
            translatedText += c;                //if c is not a consonant it leaves the character as is
        }
    }



    bool Model::isVowel(char c){      //return true if vowel and false if not
        return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' ||
        c == 'o' || c == 'O' || c == 'u' || c == 'U');
        }

    void Model::translateSingleVowel(char c, string& translatedText){
            if (isVowel(c)){
                translatedText += c;        //if vowel leave as is
    }
    }
    
Model::~Model() {
    // Destructor implementation
}
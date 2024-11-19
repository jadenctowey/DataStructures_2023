#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <string> 
using namespace std;


class Translator {
private:
    string translate;
    string s;

public:
    Translator(); // Constructor 

    string translateEnglishWord(const string& word); // word
    string translateEnglishSentence(const string& sentence); // sentence

    ~Translator(); // Destructor 
};

#endif
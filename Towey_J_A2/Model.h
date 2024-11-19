#ifndef MODEL_H
#define MODEL_H

#include <string>

class Model {
private:
    std::string translatedText;
    char c;

public:
    Model();  // Default constructor
    ~Model(); // Destructor

    bool isConsonant(char c);
    void translateSingleConsonant(char c, std::string& translatedText);
    bool isVowel(char c);
    void translateSingleVowel(char c, std::string& translatedText);
};

#endif // MODEL_H
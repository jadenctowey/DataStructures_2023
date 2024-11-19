#ifndef FILEPROCESSOR_H 
#define FILEPROCESSOR_H
#include <string>
#include <cctype>
using namespace std;


class FileProcessor {
private:
    string originalText;
    string translatedText;
public:
    FileProcessor();   // default constructor
    ~FileProcessor();  // destructor
    void processFile(const string& inputString, const string& fileName);
};

#endif
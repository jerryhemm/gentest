#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;


class Funcs {

    public:

        int readTextFile(const string &path, string &content);
        int copyFile(const string inputPath, const string outputPath);

        void splitStr(string &str, const string &seperator, vector<string> &result);

};


int Funcs::readTextFile(const string &path, string &content) {

    ifstream file;
    char word;
    stringstream strStream;

    file.open(path.c_str(), ios::in);
    if (file.fail()) return -1;

    while (strStream && file.get(word)) strStream.put(word);
    content = strStream.str();

    return 0;

}


int Funcs::copyFile(const string inputPath, const string outputPath) {

    ifstream inputFile;
    ofstream outputFile;

    inputFile.open(inputPath.c_str(), ios::binary);
    if (inputFile.fail()) return -1;

    outputFile.open(outputPath.c_str(), ios::binary);
    if (outputFile.fail()) return -2;

    outputFile << inputFile.rdbuf();

    outputFile.close();
    inputFile.close();

    return 0;

}


void Funcs::splitStr(string &str, const string &seperator, vector<string> &result) {

    int strLen = str.size();
    int seperatorLen = seperator.size();
    int pos;
    string slice;

    str += seperator;

    for (int i = 0; i < strLen; i ++) {

        pos = str.find(seperator, i);

        if (pos <= strLen) {

            slice = str.substr(i, pos - i);
            result.push_back(slice);

            i = pos + seperatorLen - 1;

        }

    }

}


#endif // FUNCS_H_INCLUDED

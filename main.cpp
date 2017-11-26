#include <iostream>
#include <string>
#include <vector>
#include "funcs.h"

using namespace std;


class MyTest {

    private:

        Funcs funcs;
        string textFilePath = "..\\files\\test.txt";
        string sampleImg1Path = "..\\files\\path.jpg";

    public:

        int readTextFile();
        int copyFile();
        int splitStr();

};


int MyTest::readTextFile() {

    string content;

    if (funcs.readTextFile(textFilePath, content) == 0) {
        cout << content << endl;
    } else {
        cout << "Failed to read text file: " << textFilePath << endl;
    }

    return 0;

}


int MyTest::copyFile() {

    string inputPath = sampleImg1Path;
    string outputPath = "..\\files\\path_copy.jpg";
    int result = funcs.copyFile(inputPath, outputPath);

    if (result == 0) {
        cout << inputPath << " is successfully copied" << endl;
    } else if (result == -1) {
        cout << "Failed to open: " << inputPath << endl;
    } else if (result == -2) {
        cout << "Failed to create: " << outputPath << endl;
    }

    return 0;

}


int MyTest::splitStr() {

    string str = textFilePath;
    string sepector = "\\";
    vector<string> slices;
    int slicesLen;

    funcs.splitStr(str, sepector, slices);
    slicesLen = slices.size();

    for (int i = 0; i < slicesLen; i ++) cout << slices[i] << endl;

    return 0;

}


int main() {

    MyTest myText;

    //myText.readTextFile();
    //myText.copyFile();
    myText.splitStr();

    return 0;

}

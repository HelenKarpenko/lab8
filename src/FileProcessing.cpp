#include <FileProcessing.h>
#include <fstream>

string FileProcessing::read(const string &filename) {
    ifstream file(filename);
    string str = "";
    if (file.is_open()) {
        file.seekg(0, ios::end);
        str.reserve(file.tellg());
        file.seekg(0, ios::beg);

        str.assign((istreambuf_iterator<char>(file)),
                   istreambuf_iterator<char>());
        file.close();
    }else{
        throw "file not open";
    }
    return str;
}
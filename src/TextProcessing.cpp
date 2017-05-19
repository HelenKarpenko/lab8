#include "TextProcessing.h"
#include <fstream>
#include <jansson.h>

TextProcessing::TextProcessing(const string &filename){
    string str = FileProcessing::read(filename);
    string title = filename.substr(filename.find_last_of("/")+1);
    this->title = title;
    this->size = fileSize(str);
    this->text = str;
}

TextProcessing::~TextProcessing(){
}

size_t TextProcessing::fileSize(const string &str) {
    return strlen(str.c_str());
}

string TextProcessing::fileInfo(){
    json_t *info = json_object();
    json_object_set_new(info, "title", json_string(this->title.c_str()));
    json_object_set_new(info, "size", json_integer(size));
    json_object_set_new(info, "text", json_string(text.c_str()));
    string jsonString = json_dumps(info, JSON_INDENT(2));
    json_decref(info);
    return jsonString;
}

string TextProcessing::fileDataInfo(){
    json_t *info = json_object();
    json_object_set_new(info, "title", json_string(this->title.c_str()));
    json_object_set_new(info, "number_count", json_integer(getCntOfNumber()));
    json_object_set_new(info, "min_number", json_integer(getMinNum()));
    string jsonString = json_dumps(info, JSON_INDENT(2));
    json_decref(info);
    return jsonString;
}

// /file/data - у відповідь клієнту відправити JSON-об'єкт із інформацією про кількість всіх цифр у файлі
// та найменше цифру (файл data.txt).
int TextProcessing::getCntOfNumber(){
    int cnt = 0;
    string cText = text.c_str();
    for(int i = 0; i < cText.length(); i++){
        if(isdigit(cText[i]) || (cText[i] = '-' && isdigit(cText[i+1]))) cnt++;
    }
    return cnt;
}



int TextProcessing::getMinNum(){
    int min = INT32_MAX;
    const char *cText = text.c_str();
    for(int i = 0; i < strlen(cText); i++){
        if(isdigit(cText[i]) || (cText[i] == '-' && isdigit(cText[i+1]))){
            int tmp = atol(cText + i);;
            if (tmp < min) {
                min = tmp;
            }
            i += to_string(tmp).length();
        }
    }
    return min;
}
/**@file
 * @brief Class for working with text
 */

#ifndef LAB8_TEXTPROCESSING_H
#define LAB8_TEXTPROCESSING_H

#include <FileProcessing.h>

using namespace std;

/**
 * @class
 * @brief defines text file representation
 */
class TextProcessing {
    string title;
    long size;
    string text;

public:
    /**
     * @brief Get size of a text in bytes
     * @param filename - name of the file
     * @return size of a text in bytes
     */
    size_t fileSize(const string &filename);
    /**
     * @brief textProcessing constructor
     * @param filename - name of the file
     */
    TextProcessing(const string &filename);
    /**
     * @brief textProcessing destructor
     */
    ~TextProcessing();
    /**
     * @brief Set all information about text in file to string
     * @return string with information
     */
    string fileInfo();
    /**
     * @brief Get count of numbers in text
     * @return count of number
     */
    int getCntOfNumber();
    /**
     * @brief Get minimal number in text
     * @return minimal number
     */
    int getMinNum();
    /**
     * @brief Set information about text in file to string
     * @return string with information
     */
    string fileDataInfo();
};


#endif //LAB8_TEXTPROCESSING_H

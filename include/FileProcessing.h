/** @file
 *  @brief Class for working with the file
 */

#ifndef LAB8_FILEPROCESSING_H
#define LAB8_FILEPROCESSING_H

#include <iostream>
using namespace std;

/**
 * @class
 * @brief defines a file processing
 */
class FileProcessing {
public:
    /**
     * @brief Reads text from file
     * @param filename - name of the file to read
     * @return content of the file
     */
    static string read(const string &filename);
};

#endif //LAB8_FILEPROCESSING_H

#ifndef TIC_TAC_TOE_TRAININGDATA_H
#define TIC_TAC_TOE_TRAININGDATA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <memory>
#include <string>
#include <array>

class TrainingData { // ** Singleton ** //
public:
    static TrainingData &getInstance(); // return instance of TrainingData class
    void open(std::string, bool); // open file to write
    void close(); // close file
    TrainingData &operator<<(const std::string&); // Overload << operator to identify string as result and write it into the file
    TrainingData &operator<<(std::vector<std::vector<double>>); // Overload << operator to identify vector as result and write it into the file

private:
    TrainingData() {}
    TrainingData(const TrainingData&) = delete;
    void operator=(const TrainingData&) = delete;
    std::ofstream outputStream;
};


#endif //TIC_TAC_TOE_TRAININGDATA_H
#ifndef TIC_TAC_TOE_TRAININGDATA_H
#define TIC_TAC_TOE_TRAININGDATA_H

#include <iostream>
#include <fstream>
#include <vector>

class TrainingData {
public:
    static TrainingData &getInstance();
    void open(std::string);
    void close();
    TrainingData &operator<<(const std::string&);
    TrainingData &operator<<(std::vector<std::vector<double>>);

private:
    TrainingData() {}
    TrainingData(const TrainingData&) = delete;
    void operator=(const TrainingData&) = delete;
    std::ofstream outputStream;
};


#endif //TIC_TAC_TOE_TRAININGDATA_H

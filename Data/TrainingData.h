#ifndef TIC_TAC_TOE_TRAININGDATA_H
#define TIC_TAC_TOE_TRAININGDATA_H

#include <iostream>
#include <fstream>
class TrainingData {
public:
    static TrainingData &getInstance();
    void open();
    void close();
    TrainingData &operator<<(const std::string&);

private:
    TrainingData() {}
    TrainingData(const TrainingData&) = delete;
    void operator=(const TrainingData&) = delete;
    std::fstream fileStream;
};


#endif //TIC_TAC_TOE_TRAININGDATA_H

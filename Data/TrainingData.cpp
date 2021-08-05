#include "TrainingData.h"

using namespace std;

TrainingData &TrainingData::getInstance()
{
    static TrainingData instance;
    return instance;
}

void TrainingData::open()
{
    try
    {
        fileStream.open("data.mat", ios::binary | ios::app);
    }
    catch (exception &err)
    {
        cout << "Error occurred in file opening: " << err.what();
    }
}

void TrainingData::close()
{
    fileStream.close();
}

TrainingData &TrainingData::operator<<(const string &s)
{
    if(fileStream.is_open())
    {
        size_t strSize = s.size();
        fileStream.write(reinterpret_cast<char*>(&strSize), sizeof(strSize));
        fileStream.write(reinterpret_cast<char*>(s[0]), strSize);
    }

    throw runtime_error("Your file stream isn't open.");
}
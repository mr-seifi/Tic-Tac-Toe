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
        outputStream.open("data.mat", ios_base::app);
    }
    catch (exception &err)
    {
        cout << "Error occurred in file opening: " << err.what();
    }
}

void TrainingData::close()
{
    outputStream.close();
}

TrainingData &TrainingData::operator<<(const string &s)
{
    if(outputStream.is_open())
    {
        string res = "";
        for(int i = 0; i < 19; ++i)
            if(i % 2 == 0)
                res += s[i];

        outputStream << res << endl;
        return (*this);
    }

    throw runtime_error("Your file stream isn't open.");
}
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
        string gameRes = s;
        string delimiter = " ";
        size_t pos = 0;

        int res;
        while ((pos = gameRes.find(delimiter)) != std::string::npos) {
            res = stoi(gameRes.substr(0, pos));
            outputStream << res << ' ';
            gameRes.erase(0, pos + delimiter.length());
        }

        outputStream << s[s.length() - 1] << endl;
        return (*this);
    }

    throw runtime_error("Your file stream isn't open.");
}
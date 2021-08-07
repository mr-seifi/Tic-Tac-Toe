#include "TrainingData.h"

using namespace std;

TrainingData &TrainingData::getInstance()
{
    static TrainingData instance;
    return instance;
}

void TrainingData::open(string s)
{
    try
    {
        outputStream.open(s, ios_base::app);
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

        double res;
        while ((pos = gameRes.find(delimiter)) != std::string::npos) {
            res = stod(gameRes.substr(0, pos));
            outputStream << res << ' ';
            gameRes.erase(0, pos + delimiter.length());
        }
        outputStream << endl;

        return (*this);
    }

    throw runtime_error("Your file stream isn't open.");
}

TrainingData &TrainingData::operator<<(std::vector<std::vector<double>> allMovements)
{
    if(outputStream.is_open())
    {
        for(int i = 0; i < allMovements.size(); ++i)
        {
            for(int j = 0; j < 9; ++j)
                outputStream << allMovements[i][j] << ' ';
            outputStream << endl;
        }
    }
    throw runtime_error("Your file stream isn't open.");
}
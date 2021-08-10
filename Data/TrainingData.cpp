#include "TrainingData.h"

using namespace std;

// Singleton design pattern.
TrainingData &TrainingData::getInstance()
{
    static TrainingData instance;
    return instance;
}

// Write mode or Append mode?
void TrainingData::open(string path, bool app)
{
    try
    {
        if(app)
            outputStream.open(path, ios_base::app);
        else
            outputStream.open(path, ios_base::out);

    }
    catch (exception &err) // Handle opening file error.
        {
        cout << "Error occurred in file opening: " << err.what();
        }
}

// Close file (it's required to apply changes).
void TrainingData::close()
{
    outputStream.close();
}

// Overload << operator for one result (string type) and write it into the file by whitespace delimiter
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
    }
    else
        throw runtime_error("Your file stream isn't open.");

    return (*this);
}

// Overload << operator for some result (vector type) and write it into the file
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
    else
        throw runtime_error("Your file stream isn't open.");

    return (*this);
}
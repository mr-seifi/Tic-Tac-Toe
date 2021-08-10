cmake_minimum_required(VERSION 3.20)
project(Tic_Tac_Toe)

set(CMAKE_CXX_STANDARD 14)
set(Headers Model/Player.h Model/Board.h Model/Game.h Data/TrainingData.h Data/OperationSystem.h)
set(Sources Model/Player.cpp Model/Board.cpp Model/Game.cpp Data/TrainingData.cpp)

add_executable(Tic_Tac_Toe main.cpp ${Sources} ${Headers})

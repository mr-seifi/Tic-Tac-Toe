# Tic-Tac-Toe
### Requirements
1. __Linux__ operating system
2. __Octave__ programming language
   2. If you want play with AI, you should install octave on your system. for check:
   `octave --version`
### Description
This is implementation of [Tic Tac Toe](https://en.wikipedia.org/wiki/Tic-tac-toe).
> #### Assets
> Include some photos about NN architecture, .... <br/> 
> _______
> #### Data
> Data directory include some headers and cpp files. <br/>
> __Training Data__ is for train data to feed NN but how? by playing random versus random. <br/>
> __OperatingSystem__ is for execute bash commands.
> _______
> #### Model
> Model directory include __Board__, __Player__ and __Game__ classes. <br/>
> __Board__ is for create board instance. by the name you can guess what each class do. <br/>
> __Player__ is for create player instance. each player has __id__, __name__, __isAI__ and __notation__. <br/>
> __Game__ is main part of Tic Tac Toe logic. each game has __set__ (calculate by number of turns), a pair of __players__ and __board__.
> _______
> #### Neural Network
> This is main part of __AI__ core. by this directory, your computer can think and after that turn a move. 
> Neural Network directory has several octave function files and one octave script which recall functions to predict next move. <br/>
> Below picture present my nn architecture which has __one input layer with 9 unit__, __a couple of hidden layers with 36 unit__ and __one output layer__ that generate __probability of me winning__.
> ![Neural Network](Assets/nn.svg)

[See more about my architecture](https://github.com/mr-seifi/Tic-Tac-Toe/tree/main/NeuralNetwork)
### Some examples of nn data
```matlab
 1 0 -1 -1 1 1 0 -1 1
 -1 0 1 0 -1 1 1 -1 -1
 -1 -1 -1 1 -1 1 0 1 0
 -1 -1 -1 1 0 1 -1 1 0
 -1 1 -1 1 -1 0 -1 1 1
 -1 -1 -1 0 1 1 0 0 1
 0 0 -1 -1 1 -1 1 1 -1
 % 1 represent it's my turn
 % 0 represent empty position
 % -1 represent it's your enemy turn
 % last column represent for 1 (i win), 0 (equal) and -1 (enemy wins)
```
### Some examples of playing
#### Human wins
![Human Wins](Assets/human_wins.gif)
___
#### AI wins
![AI Wins](Assets/ai_wins.gif)
___
#### Same
![Equal](Assets/equal.gif)

Note: Neural network can't solve this problem as good as MiniMax solution.
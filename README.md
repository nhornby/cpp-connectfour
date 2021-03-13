Personal Project: Connect Four
=======================

Author: Nolan Hornby <nhornby@umich.edu>

Date: Saturday, March 13th, 2021

# Purpose
This program is a C++ Connect Four game.

The AI makes use of a min-max algorithm with alpha-beta pruning to reach fast 12-move lookahead.

# Quick start
```console
$ g++ -std=c++11 -O3 main.cpp state.cpp player.cpp handler.cpp -o main.exe
./main.exe
```

# Command Line Options
This program defaults to 6 rows, 7 columns, with a 4-in-a-row win.

Additionally, the default strategy of both players is human input, but can be modified to "Random" or "AI"
```console
./main.exe -r [number of rows] -c [number of columns] -n [connect how many?] -1 [p1 strategy] -2 [p2 strategy]
```
Use --help argument for further detail
```console
./main.exe --help
```

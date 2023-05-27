#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <cstdlib>

class grid
{
private:
    int rows, col, generation, genCap;
    int** array;
    
public:
    // prints out the grid
    void print();

    // updates grid based on rules
    void updateGrid();

    // constructor to create the grid
    grid(int xAxis = 10, int yAxis = 10);

    // deconstructor
    ~grid();

    // set value function
    void setValue(int row, int col, int value);
    // set genCap function
    void setGenCap(int value);


    // get value function
    int getValue(int row, int col);
    // get genCap function
    int getGenCap();
    // get generation function
    int getGeneration();
    // get row function
    int getRows();
    // get col function
    int getCol();

};

#endif
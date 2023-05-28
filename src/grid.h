#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <cstdlib>
#include <random>
#include <string>

class grid
{
private:
    int rows, col, generation, genCap;
    int array[50][50];
    
public:
    // prints out the grid
    void print();
    // updates grid based on rules
    void updateGrid();
    // generates a number for the grid, 20% chance of being 1, 80% chance of being 0 
    int genNumber() const;

    // constructor to create the grid
    grid(int x);

    // set genCap function
    void setGenCap(int value);

    // get genCap function
    int getGenCap() const;
    // get generation function
    int getGeneration() const;
    // get row function
    int getRows() const;
    // get col function
    int getCol() const;
    // find neighbors of a given square
    int getNeighbors(int x, int y) const;

};

#endif
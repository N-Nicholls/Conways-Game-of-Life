#include "grid.h"


// setter functions
// set value function
void grid::setValue(int rows, int col, int value){
    array[rows][col] = value;
}


// getter functions
// get generationCap function
int grid::getGenCap(){
    return genCap;
}
// get generation function
int grid::getGeneration(){
    return generation;
}
// set genCap function
void grid::setGenCap(int value){
    genCap = value;
}
// get row function
int grid::getRows(){
    return rows;
}
// get col function
int grid::getCol(){
    return col;
}
// get value function
int grid::getValue(int rows, int col){
    return array[rows][col];
}


// misc functions
// prints out the grid
void grid::print(){
    std::system("clear");
    for(int i = 0; i < getRows(); i++){
        std::cout << "\n";
        for(int j = 0; j < getCol(); i++){
            std::cout << getValue(i, j) << " ";
        }
    }
}
// updates grid based on rules
void grid::updateGrid(){

    // create new temporary array
    int tempArray[getRows()][getCol()];
    for(int a = 0; a < getRows(); a++)
        for(int b = 0; b < getCol(); b++){
            tempArray[a][b] = getValue(a, b);
        }

    // based on position of object, count its neighbors
    for(int i = 0; i < getRows(); i++){
        for(int j = 0; j < getCol(); j++){
            int neighbors = 0;
            if(i == 0 && j == 0){ // NW 
                if(getValue(getRows()-1, getCol()-1) == 1) // top left MODIFIED
                    neighbors++;
                if(getValue(i, getCol()-1) == 1) // top right MODIFIED
                    neighbors++;
                if(getValue(getRows()-1, j) == 1) // bottom left MODIFIED
                    neighbors++;
                if(getValue(i+1, j) == 1) // bottom right MODIFIED
                    neighbors++;
            }
            else if(i == 0 && j == getCol()-1){ // NE
                if(getValue(getRows()-1, j) == 1) // top MODIFIED
                    neighbors++;
                if(getValue(i+1, j) == 1) // bottom
                    neighbors++;
                if(getValue(i, j-1) == 1) // left
                    neighbors++;
                if(getValue(i, 0) == 1) // right MODIFIED
                    neighbors++;
                if(getValue(getRows()-1, j-1) == 1) // top left MODIFIED
                    neighbors++;
                if(getValue(getRows()-1, 0) == 1) // top right MODIFIED
                    neighbors++;
                if(getValue(i+1, j-1) == 1) // bottom left
                    neighbors++;
                if(getValue(i+1, 0) == 1) // bottom right MODIFIED
                    neighbors++;
            }
            else if(i == getRows()-1 && j == 0){ // SW
                if(getValue(i-1, getCol()-1) == 1) // top left MODIFIED
                    neighbors++;
                if(getValue(i-1, j) == 1) // top right
                    neighbors++;
                if(getValue(0, getCol()-1) == 1) // bottom left MODIFIED
                    neighbors++;
                if(getValue(0, j) == 1) // bottom right
                    neighbors++;
                if(getValue(i, getCol()-1) == 1) // left MODIFIED
                    neighbors++;
                if(getValue(i, j+1) == 1) // right
                    neighbors++;
            }
            else if(i == getRows()-1 && j == getCol() -1){ // SE
                if(getValue(i-1, j) == 1) // top
                    neighbors++;
                if(getValue(0, j) == 1) // bottom MODIFIED
                    neighbors++;
                if(getValue(i, j-1) == 1) // left
                    neighbors++;
                if(getValue(i, 0) == 1) // right MODIFIED
                    neighbors++;
                if(getValue(i-1, j-1) == 1) // top left
                    neighbors++;
                if(getValue(getRows()-2, 0) == 1) // top right MODIFIED
                    neighbors++;
                if(getValue(0, getCol()-2) == 1) // bottom left MODIFIED
                    neighbors++;
                if(getValue(0, 0) == 1) // bottom right MODIFIED
                    neighbors++;
            }
            else if(i == 0){ // North
                if(getValue(getRows()-1, j) == 1) // top MODIFIED
                    neighbors++;
                if(getValue(i+1, j) == 1) // bottom
                    neighbors++;
                if(getValue(i, j-1) == 1) // left
                    neighbors++;
                if(getValue(i, j+1) == 1) // right
                    neighbors++;
                if(getValue(getRows()-1, j-1) == 1) // top left MODIFIED
                    neighbors++;
                if(getValue(getRows()-1, j+1) == 1) // top right MODIFIED
                    neighbors++;
                if(getValue(i+1, j-1) == 1) // bottom left
                    neighbors++;
                if(getValue(i+1, j+1) == 1) // bottom right
                    neighbors++;
            }
            else if(i == getRows()-1){ // South
                if(getValue(i-1, j) == 1) // top
                    neighbors++;
                if(getValue(0, j) == 1) // bottom MODIFIED
                    neighbors++;
                if(getValue(i, j-1) == 1) // left
                    neighbors++;
                if(getValue(i, j+1) == 1) // right
                    neighbors++;
                if(getValue(i-1, j-1) == 1) // top left
                    neighbors++;
                if(getValue(i-1, j+1) == 1) // top right
                    neighbors++;
                if(getValue(0, j-1) == 1) // bottom left MODIFIED
                    neighbors++;
                if(getValue(0, j+1) == 1) // bottom right MODIFIED
                    neighbors++;
            }
            else if(j == getCol() - 1){ // East
                if(getValue(i-1, j) == 1) // top
                    neighbors++;
                if(getValue(i+1, j) == 1) // bottom
                    neighbors++;
                if(getValue(i, j-1) == 1) // left
                    neighbors++;
                if(getValue(i, 0) == 1) // right MODIFIED
                    neighbors++;
                if(getValue(i-1, j-1) == 1) // top left
                    neighbors++;
                if(getValue(i-1, 0) == 1) // top right MODIFIED
                    neighbors++;
                if(getValue(i+1, j-1) == 1) // bottom left
                    neighbors++;
                if(getValue(i+1, 0) == 1) // bottom right MODIFIED
                    neighbors++;
            }
            else if(j == 0){ // West
                if(getValue(i-1, j) == 1) // top
                    neighbors++;
                if(getValue(i+1, j) == 1) // bottom
                    neighbors++;
                if(getValue(i, getCol()-1) == 1) // left MODIFIED
                    neighbors++;
                if(getValue(i, j+1) == 1) // right
                    neighbors++;
                if(getValue(i-1, getCol()-1) == 1) // top left MODIFIED
                    neighbors++;
                if(getValue(i-1, j+1) == 1) // top right
                    neighbors++;
                if(getValue(i+1, getCol()-1) == 1) // bottom left MODIFIED
                    neighbors++;
                if(getValue(i+1, j+1) == 1) // bottom right
                    neighbors++;
            }
            else{ // center square
                if(getValue(i-1, j) == 1) // top
                    neighbors++;
                if(getValue(i+1, j) == 1) // bottom
                    neighbors++;
                if(getValue(i, j-1) == 1) // left
                    neighbors++;
                if(getValue(i, j+1) == 1) // right
                    neighbors++;
                if(getValue(i-1, j-1) == 1) // top left
                    neighbors++;
                if(getValue(i-1, j+1) == 1) // top right
                    neighbors++;
                if(getValue(i+1, j-1) == 1) // bottom left
                    neighbors++;
                if(getValue(i+1, j+1) == 1) // bottom right
                    neighbors++;
            }

            // based on neighbors, update value of object
            if(getValue(i, j) == 1){
                if(neighbors < 2 || neighbors > 3)    
                    tempArray[i][j] == 0;     
            }
            if(getValue(i, j) == 0){
                if(neighbors == 3)
                    tempArray[i][j] == 1;
            }
        }
    }
    // update main array
    for(int c = 0; c < getRows(); c++)
        for(int d = 0; d < getCol(); d++){
            setValue(c, d, tempArray[c][d]);
        }
    generation++;
}


// object functions
// constructor to create the grid
grid::grid(int xAxis, int yAxis){
    rows = xAxis;
    col = yAxis;

    array = new int*[rows];
    for(int i = 0; i < rows; i++){
        array[i] = new int[col];
    }
}
// deconstructor
grid::~grid(){
    for(int i = 0; i < rows; i++){
        delete[] array[i];
    }
    delete[] array;
}



/*
// updates grid based on rules
void grid::updateGrid(){
    for(int i = 0; i < getRows(); i++){
        for(int j = 0; j < getCol(); j++){
            int neighbors = 0;
            if(i == 0 && j == 0){ // NW 

            }
            else if(i == 0 && j == getCol()-1){ // NE

            }
            else if(i == getRows()-1 && j == 0){ // SW

            }
            else if(i == getRows()-1 && j == getCol() -1){ // SE
                if(getValue(i-1, j) == 1) // top
                    neighbors++;
                if(getValue(0, getCol()-1) == 1) // bottom MODIFIED
                    neighbors++;
                if(getValue(i, j-1) == 1) // left
                    neighbors++;
                if(getValue(getRows()-1, 0) == 1) // right MODIFIED
                    neighbors++;
                if(getValue(i-1, j-1) == 1) // top left
                    neighbors++;
                if(getValue(getRows()-2, 0) == 1) // top right MODIFIED
                    neighbors++;
                if(getValue(0, getCol()-2) == 1) // bottom left MODIFIED
                    neighbors++;
                if(getValue(0, 0) == 1) // bottom right MODIFIED
                    neighbors++;
            }
            else if(i == 0){ // North
                if(getValue(getRows()-1, j) == 1) // top MODIFIED
                    neighbors++;
                if(getValue(i+1, j) == 1) // bottom
                    neighbors++;
                if(getValue(i, j-1) == 1) // left
                    neighbors++;
                if(getValue(i, j+1) == 1) // right
                    neighbors++;
                if(getValue(getRows()-1, j-1) == 1) // top left MODIFIED
                    neighbors++;
                if(getValue(getRows()-1, j+1) == 1) // top right MODIFIED
                    neighbors++;
                if(getValue(i+1, j-1) == 1) // bottom left
                    neighbors++;
                if(getValue(i+1, j+1) == 1) // bottom right
                    neighbors++;
            }
            else if(i == getRows()-1){ // South
                if(getValue(i-1, j) == 1) // top
                    neighbors++;
                if(getValue(0, j) == 1) // bottom MODIFIED
                    neighbors++;
                if(getValue(i, j-1) == 1) // left
                    neighbors++;
                if(getValue(i, j+1) == 1) // right
                    neighbors++;
                if(getValue(i-1, j-1) == 1) // top left
                    neighbors++;
                if(getValue(i-1, j+1) == 1) // top right
                    neighbors++;
                if(getValue(0, j-1) == 1) // bottom left MODIFIED
                    neighbors++;
                if(getValue(0, j+1) == 1) // bottom right MODIFIED
                    neighbors++;
            }
            else if(j == getCol() - 1){ // East
                if(getValue(i-1, j) == 1) // top
                    neighbors++;
                if(getValue(i+1, j) == 1) // bottom
                    neighbors++;
                if(getValue(i, j-1) == 1) // left
                    neighbors++;
                if(getValue(i, 0) == 1) // right MODIFIED
                    neighbors++;
                if(getValue(i-1, j-1) == 1) // top left
                    neighbors++;
                if(getValue(i-1, 0) == 1) // top right MODIFIED
                    neighbors++;
                if(getValue(i+1, j-1) == 1) // bottom left
                    neighbors++;
                if(getValue(i+1, 0) == 1) // bottom right MODIFIED
                    neighbors++;
            }
            else if(j == 0){ // West
                if(getValue(i-1, j) == 1) // top
                    neighbors++;
                if(getValue(i+1, j) == 1) // bottom
                    neighbors++;
                if(getValue(i, getCol()-1) == 1) // left MODIFIED
                    neighbors++;
                if(getValue(i, j+1) == 1) // right
                    neighbors++;
                if(getValue(i-1, getCol()-1) == 1) // top left MODIFIED
                    neighbors++;
                if(getValue(i-1, j+1) == 1) // top right
                    neighbors++;
                if(getValue(i+1, getCol()-1) == 1) // bottom left MODIFIED
                    neighbors++;
                if(getValue(i+1, j+1) == 1) // bottom right
                    neighbors++;
            }
            else{ // center square
                if(getValue(i-1, j) == 1) // top
                    neighbors++;
                if(getValue(i+1, j) == 1) // bottom
                    neighbors++;
                if(getValue(i, j-1) == 1) // left
                    neighbors++;
                if(getValue(i, j+1) == 1) // right
                    neighbors++;
                if(getValue(i-1, j-1) == 1) // top left
                    neighbors++;
                if(getValue(i-1, j+1) == 1) // top right
                    neighbors++;
                if(getValue(i+1, j-1) == 1) // bottom left
                    neighbors++;
                if(getValue(i+1, j+1) == 1) // bottom right
                    neighbors++;
            }
        }
    }
}
*/
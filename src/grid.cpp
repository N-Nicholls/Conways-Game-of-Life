#include "grid.h"


// setter functions
// set genCap function
void grid::setGenCap(int value){
    genCap = value;
}


// getter functions
// get generationCap function
int grid::getGenCap() const{
    return genCap;
}
// get generation function
int grid::getGeneration() const{
    return generation;
}
// get row function
int grid::getRows() const{
    return rows;
}
// get col function
int grid::getCol() const{
    return col;
}


// misc functions
// prints out the grid
void grid::print(){
    std::system("clear");
    for(int i = 0; i < rows; i++){
        std::cout << "\n";
        for(int j = 0; j < col; j++){

            if(array[i][j] == 1)
                std::cout << '#';
            else
                std:: cout << ' ';
            std::cout << " ";
        }
    }
    std::cout << std::endl << "Generation: " << generation << "/" << genCap;
}
// updates grid based on rules
void grid::updateGrid(){
    int neighbors = 0;
    generation++;
    // create new temporary array
    int tempArray[rows][col];

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < col; j++){
            neighbors = getNeighbors(i, j);
            if(array[i][j] == 1){
                if(neighbors < 2 || neighbors > 3)    
                    tempArray[i][j] = 0;     
            }
            if(array[i][j] == 0){
                if(neighbors == 3)
                    tempArray[i][j] = 1;
            }
        }
    }
    // update main array
    for(int k = 0; k < rows; k++)
        for(int l = 0; l < col; l++){
            array[k][l] = tempArray[k][l];
        }
}
// generates a number for the grid, 20% chance of being 1, 80% chance of being 0
int grid::genNumber() const{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double randomNumber = dis(gen);

    if(randomNumber <= 0.2){
        randomNumber = 1;
    }
    else
        randomNumber = 0;
    return randomNumber;
}
// find neighbors of a given square
int grid::getNeighbors(int x, int y) const{
    int neighbors = 0;
    int i = x;
    int j = y;
    if(i == 0 && j == 0){ // NW 
        if(array[rows-1][0] == 1) // top MODIFIED
            neighbors++;
        if(array[i+1][j] == 1) // bottom 
            neighbors++;
        if(array[0][col-1] == 1) // left MODIFIED
            neighbors++;
        if(array[i][j+1] == 1) // right 
            neighbors++;
        if(array[rows-1][col-1] == 1) // top left MODIFIED
            neighbors++;
        if(array[rows-1][1] == 1) // top right MODIFIED
            neighbors++;
        if(array[1][col-1] == 1) // bottom left MODIFIED
            neighbors++;
        if(array[i+1][j+1] == 1) // bottom right 
            neighbors++;
    }
    else if(i == 0 && j == col-1){ // NE
        if(array[rows-1][col-1] == 1) // top MODIFIED
            neighbors++;
        if(array[i+1][j] == 1) // bottom 
            neighbors++;
        if(array[i][j-1] == 1) // left 
            neighbors++;
        if(array[0][0] == 1) // right MODIFIED
            neighbors++;
        if(array[rows-1][col-2] == 1) // top left MODIFIED
            neighbors++;
        if(array[rows-1][0] == 1) // top right MODIFIED
            neighbors++;
        if(array[i+1][j-1] == 1) // bottom left 
            neighbors++;
        if(array[1][0] == 1) // bottom right MODIFIED
            neighbors++;
    }
    else if(i == rows-1 && j == 0){ // SW
        if(array[i-1][j] == 1) // top
            neighbors++;
        if(array[0][0] == 1) // bottom MODIFIED
            neighbors++;
        if(array[rows-1][col-1] == 1) // left MODIFIED
            neighbors++;
        if(array[i][j+1] == 1) // right
            neighbors++;
        if(array[rows-2][col-1] == 1) // top left MODIFIED
            neighbors++;
        if(array[i-1][j+1] == 1) // top right
            neighbors++;
        if(array[0][col-1] == 1) // bottom left MODIFIED
            neighbors++;
        if(array[0][1] == 1) // bottom right MODIFIED
            neighbors++;
    }
    else if(i == rows-1 && j == col-1){ // SE
        if(array[i-1][j] == 1) // top
            neighbors++;
        if(array[0][col-1] == 1) // bottom MODIFIED
            neighbors++;
        if(array[i][j-1] == 1) // left
            neighbors++;
        if(array[rows-1][0] == 1) // right MODIFIED
            neighbors++;
        if(array[i-1][j-1] == 1) // top left
            neighbors++;
        if(array[rows-2][0] == 1) // top right MODIFIED
            neighbors++;
        if(array[0][col-2] == 1) // bottom left MODIFIED
            neighbors++;
        if(array[0][0] == 1) // bottom right MODIFIED
            neighbors++;
    }
    else if(i == 0){ // North
        if(array[rows-1][j] == 1) // top MODIFIED
            neighbors++;
        if(array[i+1][j] == 1) // bottom
            neighbors++;
        if(array[i][j-1] == 1) // left
            neighbors++;
        if(array[i][j+1] == 1) // right
            neighbors++;
        if(array[rows-1][j-1] == 1) // top left MODIFIED
            neighbors++;
        if(array[rows-1][j+1] == 1) // top right MODIFIED
            neighbors++;
        if(array[i+1][j-1] == 1) // bottom left
            neighbors++;
        if(array[i+1][j+1] == 1) // bottom right
            neighbors++;
    }
    else if(i == rows-1){ // South
        if(array[i-1][j] == 1) // top
            neighbors++;
        if(array[0][j] == 1) // bottom MODIFIED
            neighbors++;
        if(array[i][j-1] == 1) // left
            neighbors++;
        if(array[i][j+1] == 1) // right
            neighbors++;
        if(array[i-1][j-1] == 1) // top left
            neighbors++;
        if(array[i-1][j+1] == 1) // top right
            neighbors++;
        if(array[0][j-1] == 1) // bottom left MODIFIED
            neighbors++;
        if(array[0][j+1] == 1) // bottom right MODIFIED
            neighbors++;
    }
    else if(j == col-1){ // East
        if(array[i-1][j] == 1) // top
            neighbors++;
        if(array[i+1][j] == 1) // bottom
            neighbors++;
        if(array[i][j-1] == 1) // left
            neighbors++;
        if(array[i][0] == 1) // right MODIFIED
            neighbors++;
        if(array[i-1][j-1] == 1) // top left
            neighbors++;
        if(array[i-1][0] == 1) // top right MODIFIED
            neighbors++;
        if(array[i+1][j-1] == 1) // bottom left
            neighbors++;
        if(array[i+1][0] == 1) // bottom right MODIFIED
            neighbors++;;
    }
    else if(j == 0){ // West
        if(array[i-1][j] == 1) // top
            neighbors++;
        if(array[i+1][j] == 1) // bottom
            neighbors++;
        if(array[i][col-1] == 1) // left MODIFIED
            neighbors++;
        if(array[i][j+1] == 1) // right
            neighbors++;
        if(array[i-1][col-1] == 1) // top left MODIFIED
            neighbors++;
        if(array[i-1][j+1] == 1) // top right
            neighbors++;
        if(array[i+1][col-1] == 1) // bottom left MODIFIED
            neighbors++;
        if(array[i+1][j+1] == 1) // bottom right
            neighbors++;
    }
    else{ // center square
        if(array[i-1][j] == 1) // top
            neighbors++;
        if(array[i+1][j] == 1) // bottom
            neighbors++;
        if(array[i][j-1] == 1) // left
            neighbors++;
        if(array[i][j+1] == 1) // right
            neighbors++;
        if(array[i-1][j-1] == 1) // top left
            neighbors++;
        if(array[i-1][j+1] == 1) // top right
            neighbors++;
        if(array[i+1][j-1] == 1) // bottom left
            neighbors++;
        if(array[i+1][j+1] == 1) // bottom right
            neighbors++;
    }

    return neighbors;
}

// object functions
// constructor to create the grid
grid::grid(int x){
    rows = 50;
    col = 50;
    generation = 0;
    genCap = x;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < col; j++){
            array[i][j] = genNumber();
        }
    }
}
# Conways Game of Life 

## Noah Nicholls

## Project Description

Conways Game of Life is a game with no players, only being based on the initial factors of the game grid. It is a game of cellular automation, 
in which cells replicate or die on a grid based on the amount of neighbors next to them. The rules governing cellular automation, which in turn
are the rules for the entire game, are this:

1. Any living cell with less than two neighbors dies (underpopulation)

2. Any living cell with two or three neighbors lives to the next generation

3. Any living cell with more than three neighbors dies (overpopulation)

4. Lastly, any dead cell with exactly three live neighbors comes back to life (reproduction)

These rules, while quite simple, can result in some fascinating combinations.

## Implementation

The code works by making a 2D array of an arbitrary size, in this case a 100x100 grid of int values, either 1 or 0. To generate the seed a simple
random number generator is used that has a 20% chance of generating a "1", or a live cell, and an 80% chance to generate a "0", or an empty cell.
The program is then run on a loop of printing the output (which outputs empty spaces for a "0" and a "#" for a live cell) and then updating the grid
and incrementing the current generation. The update grid is where the "meat" of the program is. It goes from pos to pos on the grid and finds out the 
living cells neighboring each square. Then, based on the square's state, it will decide if it is alive or dead in the next generation. 
The next "generation" is stored in a temporary array during this time, slowly accumulating each positions value, and then when all squares have been updated
the values of the temp array are passed back to the main array. The generation is also incremented at this time.
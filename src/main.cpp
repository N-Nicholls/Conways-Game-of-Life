#include "grid.h"


int main(){

    grid thing(10, 10);
    thing.setGenCap(10);
    thing.setValue(3,3, 1);
    thing.setValue(3,2, 1);
    thing.setValue(3,1, 1);
    do{
        thing.print();
        thing.updateGrid();

    }while(thing.getGeneration() < thing.getGenCap());


    return 0;
}
#include "grid.h"

std::string pause();

int main(){
    std::string quit;
    grid thing(5000);
    do{
    thing.print();
    thing.updateGrid();
    quit = pause();
    }while(thing.getGeneration() < thing.getGenCap() || quit != "quit");
    return 0;
}


 std::string pause(){
    std::cout << "\nPress Enter to continue...\n";
    std::string dummy;
    std::getline(std::cin, dummy);
    return dummy;
}
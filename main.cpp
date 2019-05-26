#include <iostream>
#include "SDL_Plotter.h"

using namespace std;

int main(int argc, char** argv) {
    SDL_Plotter g(1000, 1000);
    
    while(!g.getQuit()){
        if(g.kbhit()){
            char c = g.getKey();
            
            
        }
        g.clear();
        g.plotPixel(100, 100, 0, 0, 0);
        g.update();
    }
    return 0;
}
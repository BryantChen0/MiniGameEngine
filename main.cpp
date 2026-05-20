#include "Math/Vector2.h"
#include "Object.h"
#include "iostream"
#include "Object.h"
#include <SDL2/SDL.h>
using namespace std;

int main(){
    Object testObj;
    bool running = true;

    testObj.position = {0, 10};
    testObj.velocity = {10, 10};
    float dt = 1.0;

    while(running){
        testObj.input();
        testObj.update(dt);
        testObj.render();
        dt++;
        if (dt > 3){
            running = false;
        }
    }

    return 0;
}

#include <iostream>

/*#include "Constants.hpp"
#include "Point.hpp"*/
#include "Engine/GameEngine.hpp"
#include "Graphics/GraphicsEngine.hpp"/*
#include "Data/AICar.hpp"
#include "Data/Car.hpp"*/
#include "Data/GameData.hpp"

using namespace std;

int main()
{
   	GameEngine *go = new GameEngine();
    go->create();
    go->execute();
    
    return 0;
}
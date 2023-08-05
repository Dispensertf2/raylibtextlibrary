
#include "text.hpp"
#include "raylib.h"

#include <iostream>


int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 600;
    
    int fontScale = 2;

    InitWindow(screenWidth, screenHeight, "Text Engine");

    FontSet cset; //cset is character set
    cset.font = LoadTexture("./ansifont8x12.png"); //ansifont8x12 is a 8px wide 12px tall font set, kind of formated like dwarf fortress but a bit off
    cset.fWidth = 8;
    cset.fHeight = 12;
    cset.rowSize = 16 - 1;
    cset.columnSize = 17 - 1;

    charIndex defaultTile = { 15,2 };

    int playerx = 0;
    int playery = 0;

    // Main game loop
    while (!WindowShouldClose())    
    {
        BeginDrawing();

        ClearBackground(BLACK);

        //Demo Code
        if (IsKeyPressed(KEY_RIGHT)) playerx += 1;
        if (IsKeyPressed(KEY_LEFT)) playerx += -1;
        if (IsKeyPressed(KEY_UP)) playery += -1;
        if (IsKeyPressed(KEY_DOWN)) playery += 1;
        //Draw World
        for (int y = 0; y < screenHeight / cset.fHeight; y++)
        {
            for (int x = 0; x < screenWidth / cset.fWidth; x++)
            {
                insertChar(x*fontScale*cset.fWidth, y*fontScale*cset.fHeight, defaultTile.x, defaultTile.y, cset, fontScale,BLACK,GREEN);

            }

        }
        insertChar(playerx * fontScale * cset.fWidth, playery * fontScale * cset.fHeight, 1, 0, cset, fontScale);
        insertStr("Health: 0 | MP: 0 | Weapon: None | Inventory - I", 0, screenHeight - cset.fHeight * fontScale, cset, fontScale,WHITE,BLACK);

        EndDrawing();
        
    }
    UnloadTexture(cset.font);
    CloseWindow(); 


    return 0;
}
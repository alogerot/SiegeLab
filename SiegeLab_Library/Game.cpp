#include "pch.h"
#include "framework.h"

#include "Game.h"
#include "CameraManager.h"
#include "SceneObjects.h"
#include "PillarBlock.h"
#include "StandardProjectile.h"
#include "LevelBuilder.h"

#include <raylib.h>

void Game::Run()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera mode");
    InputManager input;
	CameraManager camManager(0, &input);
    // Define the camera to look into our 3d world
    Camera3D camera = camManager.getCamera();


	SceneObjects sceneObjects;
    LevelBuilder level;
    level.buildPillarCube(sceneObjects);
    


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        input.Update();
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        camManager.update(GetFrameTime(), camera);
        BeginMode3D(camera);

        sceneObjects.drawAll();

        DrawGrid(10, 1.0f);

        EndMode3D();

        DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

        DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

}

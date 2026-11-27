#include "pch.h"
#include "framework.h"

#include "Game.h"
#include "CameraManager.h"
#include "PillarBlock.h"
#include "StandardProjectile.h"
#include "LevelBuilder.h"
#include "Launcher.h"
#include <raylib.h>
#include "Canon.h"

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
    
    Launcher launcher(0.f, 54.f, 15.f, &input, ProjectileKind::Light,&sceneObjects);
    EntityId id = sceneObjects.create_Entity<StandardProjectile>(base_transform_data{ {-10,4,1} }, Vector3{12,2,1});

    LevelBuilder level;
    level.buildPillarCube(sceneObjects);


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        input.Update();
        launcher.Update(GetFrameTime());
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
        sceneObjects.updateAll(GetFrameTime());
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

#include <raylib.h>
#include <ctime>
#include <iostream>

#define RAYGUI_IMPLEMENTATION

#include "extras/raygui.h"

using namespace std;


Vector2 dvizh(Vector2 player, int speed) {
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        player.x = player.x - speed * 1.2;
    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        player.x = player.x + speed * 1.2;
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        player.y = player.y + speed * 1.2;
    }
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        player.y = player.y - speed * 1.2;
    }
    if (player.x > 1887) {
        player.x = 1887;
    }
    if (player.x < 30) {
        player.x = 30;
    }
    if (player.y > 898) {
        player.y = 898;
    }
    if (player.y < 130) {
        player.y = 130;
    }
    return player;
}

Vector2 ball1(Vector2 b1, int k1x, int k1y) {
    if (b1.x > 1907) {
        k1x = k1x * -1;
    } else {
        if (b1.x < 10) {
            k1x = k1x * -1;
        }
    }
    if (b1.y > 918) {
        k1y = k1y * -1;
    } else {
        if (b1.y < 110) {
            k1y = k1y * -1;
        }
    }

    return b1;
}

Vector2 ball2(Vector2 b2, int k2x, int k2y) {
    if (b2.x > 1907) {
        k2x = k2x * -1;
    } else {
        if (b2.x < 10) {
            k2x = k2x * -1;
        }
    }
    if (b2.y > 918) {
        k2y = k2y * -1;
    } else {
        if (b2.y < 110) {
            k2y = k2y * -1;
        }
    }

    return b2;
}

Vector2 ball3(Vector2 b3, int k3x, int k3y) {
    if (b3.x > 1907) {
        k3x = k3x * -1;
    } else {
        if (b3.x < 10) {
            k3x = k3x * -1;
        }
    }
    if (b3.y > 918) {
        k3y = k3y * -1;
    } else {
        if (b3.y < 110) {
            k3y = k3y * -1;
        }
    }

    return b3;
}

void
main2(int speed, Vector2 player, bool IsGameActive, int k1x, int k1y, int k2x, int k2y, int k3x, int k3y, Vector2 b1,
      Vector2 b2, Vector2 b3) {

    while (!WindowShouldClose() && IsGameActive == true) {
        BeginDrawing();
        ClearBackground(YELLOW);
        DrawRectangle(0, 928, 1917, 100, GRAY);
        DrawRectangle(0, 0, 1917, 100, GRAY);
        DrawCircle(player.x, player.y, 30, RED);
        DrawCircle(b1.x, b1.y, 10, GREEN);
        DrawCircle(b2.x, b2.y, 30, GREEN);
        DrawCircle(b3.x, b3.y, 30, GREEN);
        player = dvizh(player, speed);

        EndDrawing();

    }
    CloseWindow();
}

int main() {
    int k1x = 1;
    int k2x = 1;
    int k3x = 1;
    int k1y = 1;
    int k2y = 1;
    int k3y = 1;
    int speed = 5;
    bool IsGameActive = true;
    Vector2 player = {100, 300};
    Vector2 b1 = {200, 200};
    Vector2 b2 = {500, 500};
    Vector2 b3 = {700, 700};
    const int screenWidth = 1917;
    const int screenHeight = 1037;
    InitWindow(screenWidth, screenHeight, "evades io parody");
    SetTargetFPS(60);
    main2(speed, player, IsGameActive, k1x, k1y, k2x, k2y, k3x, k3y, b1, b2, b3);

}
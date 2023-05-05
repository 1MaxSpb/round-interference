#include <raylib.h>
#include <ctime>
#include <iostream>

#define RAYGUI_IMPLEMENTATION

#include "extras/raygui.h"

using namespace std;


const int screenWidth = 1915;
const int screenHeight = 1037;
bool isGameActive = false;
Vector2 vec = GetMousePosition();
Vector2 dudl = {500, 300};
Texture2D dud;
Texture2D fone;
int j = 950;
int n = 0;
int a;
int t = 300;
int dof;
int aa = 0;
Rectangle ac;
Rectangle ab;

void platform(int i) {

    DrawRectangle(i, j, 300, 20, GREEN);
}

void dvizh(int i) {
    ac = {dudl.x + 80, dudl.y + 120, (float) (dud.width * 0.5), (float) (dud.height * 0.5)};
    ab = {dudl.x, dudl.y + 120, (float) (dud.width * 0.5), (float) (dud.height * 0.5)};
    if (CheckCollisionRecs(ac, {i, j, 300, 20}) || CheckCollisionRecs(ab, {i, j, 300, 20})) {
        aa++;
        a = 85;
        dudl.y=dudl.y-10;
    } else {
        dudl.y = dudl.y + 7;
    }
    if (IsKeyDown(KEY_LEFT)) {
        dudl.x = dudl.x - 40;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        dudl.x = dudl.x + 40;
    }
    if (a > 0) {
        dudl.y=dudl.y-14;
        a--;
    }
}

void main2() {
    dudl.x=500;
    dudl.y=300;
    int i;
    int j = 950;
    int n = 0;
    int a;
    int t = 300;
    int dof;
    int aa = 0;
    SetRandomSeed(time(0));
    i = GetRandomValue(0, 1615);
    const int screenWidth = 1915;
    const int screenHeight = 1037;
    bool isGameActive;
    Color color;


    Texture2D dud = LoadTexture("dudljump.png");
    Texture2D fone = LoadTexture("dudljumpfone.png");
    int exitall = 0;
    while (!WindowShouldClose() && exitall == 0) {
        if (!isGameActive) {
            Vector2 vec = GetMousePosition();
            if (vec.x < 50 && vec.y < 50 && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                exitall = 1;
            }
            if (vec.x > 49 && vec.y > 0 && IsMouseButtonDown(MOUSE_BUTTON_LEFT) ||
                vec.x > 0 && vec.y > 49 && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                isGameActive = true;
            }
            BeginDrawing();
            ClearBackground(WHITE);
            DrawText("exit", 10, 10, 20, BLACK);
            DrawRectangle(0, 0, 50, 50, color);
            DrawRectangle(0, 50, 50, 987, GREEN);
            DrawRectangle(50, 0, 1865, 50, GREEN);
            DrawRectangle(50, 50, 1865, 987, GREEN);
            DrawText("start", 800, 500, 40, BLACK);
            EndDrawing();

        } else {
            if (dudl.y < 1050) {
                if (dof > 300) {
                    t--;
                    t--;
                    t--;
                    dof = 0;
                }
                if (n > t) {
                    n = 0;
                    i = GetRandomValue(0, 1615);
                }
                ClearBackground(WHITE);
                BeginDrawing();
                ab = {dudl.x, dudl.y + 120, (float) (dud.width * 0.5), (float) (dud.height * 0.5)};
                ac = {dudl.x + 80, dudl.y + 120, (float) (dud.width * 0.5), (float) (dud.height * 0.5)};
                DrawRectangle(ac.x, ac.y, ac.width, ac.height, WHITE);
                DrawRectangle(ab.x, ab.y, ab.width, ab.height, WHITE);
                if (dudl.x < -2) {
                    dudl.x = 1910;
                }
                if (dudl.x > 1912) {
                    dudl.x = -1;
                }
                DrawTextureEx(fone, {0, 0}, 0, 1, WHITE);
                platform(i);
                DrawTextureEx(dud, {dudl.x, dudl.y}, 0, 0.5, WHITE);
                DrawText(to_string(aa).c_str(), 100, 100, 15, BLACK);
                dvizh(i);
                EndDrawing();
                n++;
                dof++;
            } else {
                BeginDrawing();
                ClearBackground(WHITE);
                DrawRectangle(1775, 0, 130, 50, GREEN);
                DrawText("restart", 1790, 10, 20, BLACK);
                EndDrawing();
                Vector2 vec = GetMousePosition();
                if (vec.x > 1785 && vec.x <1915 && IsMouseButtonDown(MOUSE_BUTTON_LEFT) &&
                    vec.y > 0 && vec.y < 49 && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                    main2();
                }
            }
        }
    }
    CloseWindow();
}

int main() {
    InitWindow(screenWidth, screenHeight, "raylib [core] example");
    SetTargetFPS(60);
    main2();
}
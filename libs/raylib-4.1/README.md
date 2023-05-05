#include <raylib.h>
#include <ctime>
#include <iostream>

#define RAYGUI_IMPLEMENTATION

#include "extras/raygui.h"

using namespace std;


bool die = false;
float A;
float B;
float C;
float D;
Texture2D monster1;
Vector2 monst1 = {0, 0};
Vector2 orig = {0, 0};
Texture2D dudfire;
const int screenWidth = 1915;
const int screenHeight = 1037;
bool isGameActive = false;
Vector2 vec = GetMousePosition();
Vector2 dudl = {500, 300};
Vector2 fire = {-500, -500};
Texture2D dud;
Texture2D fone;
int j = 950;
int n = 0;
int a;
int t = 150;
int dof;
int aa = 0;
int i;
Rectangle ac;
Rectangle ab;


void platform(Vector2 plat,Texture2D platforms) {
DrawRectangle(plat.x,plat.y,300,20,GREEN);
DrawTextureEx(platforms, plat, 0, 1, WHITE);
}

void monsters() {
int speed = 3;
A = dudl.y - monst1.y;
B = dudl.x - monst1.x;
D = A / sqrt(B * B + A * A);
C = B / sqrt(B * B + A * A);
monst1.x = monst1.x + C * speed;
monst1.y = monst1.y + D * speed;
if (CheckCollisionCircleRec(fire, 10, {monst1.x, monst1.y, 80, 100})) {
monst1.x = -1000;
monst1.y = -1000;
}
if (CheckCollisionRecs({dudl.x, dudl.y, dud.width, dud.height}, {monst1.x, monst1.y, 80, 100})) {
die = true;
}
}

void dvizh(int i) {
ac = {dudl.x + 80, dudl.y + 120, (float) (dud.width * 0.5), (float) (dud.height * 0.5)};
ab = {dudl.x, dudl.y + 120, (float) (dud.width * 0.5), (float) (dud.height * 0.5)};
if (CheckCollisionRecs(ac, {i, j, 300, 20}) || CheckCollisionRecs(ab, {i, j, 300, 20})) {
aa++;
a = 85;
dudl.y = dudl.y - 10;
} else {
dudl.y = dudl.y + 8;
}
if (IsKeyDown(KEY_LEFT)) {
dudl.x = dudl.x - 40;
}
if (IsKeyDown(KEY_RIGHT)) {
dudl.x = dudl.x + 40;
}
if (a > 0) {
dudl.y = dudl.y - 14;
a--;
}
}

void main2() {
Vector2 plat = {i,j};
dudl.x = 500;
dudl.y = 300;
SetRandomSeed(time(0));
i = GetRandomValue(0, 1615);
const int screenWidth = 1915;
const int screenHeight = 1037;
bool isGameActive;
Color color;
Texture2D dud = LoadTexture("dudljump.png");
Texture2D dudfire = LoadTexture("dudljumpfire.png");
Texture2D fone = LoadTexture("dudljumpfone.png");
Texture2D monster1 = LoadTexture("monster1.png");
Texture2D platforms = LoadTexture("platform.png");
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
if (dudl.y < 1050 && die == false) {
if (dof > 360) {
t = t - 2;
dof = 0;
}
if (n > t && j - dudl.y > 350) {
n = 0;
i = GetRandomValue(0, 1615);
}
Vector2 plat = {i,j};
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
platform (plat,platforms);
if (IsKeyDown(KEY_SPACE)) {
DrawTextureEx(dudfire, {dudl.x, dudl.y}, 0, 1.4, WHITE);
fire = {dudl.x + 47, dudl.y - 20};
} else {
DrawTextureEx(dud, {dudl.x, dudl.y}, 0, 0.5, WHITE);
}
DrawTexturePro(monster1, {130, 0, 80, 100}, {monst1.x, monst1.y, 80, 100}, orig, 1, WHITE);
DrawText(to_string(aa).c_str(), 100, 100, 15, BLACK);
dvizh(i);
monsters();
n++;
dof++;
fire.y = fire.y - 20;
DrawCircle(fire.x, fire.y, 20, RED);
// DrawRectangle(dudl.x,dudl.y,dud.width,dud.height,GREEN);
// DrawRectangle(monst1.x,monst1.y,80,100,GREEN);
EndDrawing();
} else {
BeginDrawing();
ClearBackground(WHITE);
DrawRectangle(1775, 0, 130, 50, GREEN);
DrawText("restart", 1790, 10, 20, BLACK);
EndDrawing();
Vector2 vec = GetMousePosition();
if (vec.x > 1785 && vec.x < 1915 && IsMouseButtonDown(MOUSE_BUTTON_LEFT) &&
vec.y > 0 && vec.y < 49 && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
monst1 = {0, 0};
dudl = {500, 300};
fire = {-500, -500};
die = false;
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
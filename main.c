#include "x_window.h"

int CALLBACK WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int cmdShow) {
    MainWindow mainWindow;
    InitWindow(&mainWindow, "green", 600, 600);
    StartWindow(&mainWindow, hInst, cmdShow);
}

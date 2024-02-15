#include "src/x_window.h"

int CALLBACK WinMain(HINSTANCE hInst, HINSTANCE xHinst, LPSTR lpstr, int cmdShow) {
    MainWindow mainWindow;
    InitWindow(&mainWindow, "green", 600, 600);
    StartWindow(&mainWindow, hInst, cmdShow);

    return 0;
}

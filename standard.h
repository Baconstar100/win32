#ifndef TESTING_STANDARD_H
#define TESTING_STANDARD_H

#include <windows.h>

typedef struct {
    int width;
    int height;
    HWND xHwnd;
    RECT windowRect;
    char title[];
} MainWindow;


void ShowPara(WPARAM paraW, LPARAM paraL);


void ShowPara(WPARAM paraW, LPARAM paraL) {
    printf("%llu\n%llu\n", paraW, paraL);
}


#endif //TESTING_STANDARD_H

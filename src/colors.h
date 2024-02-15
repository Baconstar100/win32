#include "standard.h"


void PrintRGB(COLORREF x);
BOOL CheckLimit(int currAmt, int changeAmt, int limit);
void PaintRect(HWND xHwnd, HDC xHdc, PAINTSTRUCT* xPs, int wParam, int amt);
COLORREF LetterColor(int charDec);


void PrintRGB(COLORREF x) {
    printf("R: %d\nG:%d\nB: %d\n\n", GetRValue(x), GetGValue(x), GetBValue(x));
}

BOOL CheckLimit(int currAmt, int changeAmt, int limit) {
    if (changeAmt > 0) {
        return ((currAmt + changeAmt) >= limit);
    } else if (changeAmt < 0) {
        return ((currAmt + changeAmt) <= limit);
    }
}

void PaintRect(HWND xHwnd, HDC xHdc, PAINTSTRUCT* xPs, int wParam, int amt) {
    xHdc = BeginPaint(xHwnd, xPs);
    
    static COLORREF currColor = RGB(255, 255, 255);
    
    int currRedVal = GetRValue(currColor);
    int currGreenVal = GetGValue(currColor);
    int currBlueVal = GetBValue(currColor);
    

    if (wParam == VK_OEM_PLUS) {
        if (CheckLimit(currRedVal, amt, 255)) {
            MessageBoxW(xHwnd, L"The color is already at the max", L"Limit", 0);
        } else {
            currColor = RGB((currRedVal += amt), (currGreenVal += amt), (currBlueVal += amt));
        }
    } else if (wParam == VK_OEM_MINUS) {
        if (CheckLimit(currRedVal, -amt, 0)) {
            MessageBoxW(xHwnd, L"The color is already at the min", L"Limit", 0);
        } else {
            currColor = RGB((currRedVal -= amt), (currGreenVal -= amt), (currBlueVal -= amt));
        }
    } else if ('A' <= wParam && wParam <= 'Z') {
        int x = LetterColor(wParam);
        currColor = RGB((currRedVal = x), (currGreenVal = x), (currBlueVal = x));
    }

    FillRect(xHdc, &xPs->rcPaint, CreateSolidBrush(currColor));
    EndPaint(xHwnd, xPs);
}


COLORREF LetterColor(int charDec) {
    switch (charDec) {
        case 'Q':
            return RGB(9, 9, 9);

        case 'W':
            return RGB(18, 18, 18);

        case 'E':
            return RGB(27, 27, 27);

        case 'R':
            return RGB(36, 36, 36);

        case 'T':
            return RGB(45, 45, 45);

        case 'Y':
            return RGB(54, 54, 54);

        case 'U':
            return RGB(63, 63, 63);

        case 'I':
            return RGB(72, 72, 72);

        case 'O':
            return RGB(81, 81, 81);

        case 'P':
            return RGB(90, 90, 90);

        case 'A':
            return RGB(99, 99, 99);

        case 'S':
            return RGB(108, 108, 108);

        case 'D':
            return RGB(117, 117, 117);

        case 'F':
            return RGB(126, 126, 126);

        case 'G':
            return RGB(135, 135, 135);

        case 'H':
            return RGB(144, 144, 144);

        case 'J':
            return RGB(153, 153, 153);

        case 'K':
            return RGB(162, 162, 162);

        case 'L':
            return RGB(171, 171, 171);

        case 'Z':
            return RGB(180, 180, 180);

        case 'X':
            return RGB(189, 189, 189);

        case 'C':
            return RGB(199, 199, 199);

        case 'V':
            return RGB(208, 208, 208);

        case 'B':
            return RGB(217, 217, 217);

        case 'N':
            return RGB(226, 226, 226);

        case 'M':
            return RGB(235, 235, 235);

        default:
            return RGB(255, 255, 255);
            break;
    }
}

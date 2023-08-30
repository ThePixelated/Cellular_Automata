#ifndef BUFFERSET_H
#define BUFFERSET_H

#include <iostream>
#include <windows.h>

void ClearBuffers(CHAR_INFO backBuffer[], CHAR_INFO frontBuffer[], short int BufferWidth, short int BufferHeight);
void SwapBuffers(CHAR_INFO backBuffer[], CHAR_INFO frontBuffer[], HANDLE consoleHandle, short int BufferWidth, short int BufferHeight);
void DrawToBackBuffer(CHAR_INFO backBuffer[], CHAR_INFO frontBuffer[], int x, int y, char ch, WORD attributes, short int BufferWidth, short int BufferHeight);
void RenderFrame(CHAR_INFO backBuffer[], CHAR_INFO frontBuffer[], int** grid, short int BufferWidth, short int BufferHeight);
void corner_coorBuff(int ScreenWidth, int ScreenHeight);

#endif
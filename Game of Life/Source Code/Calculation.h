#ifndef CALCULATION_H
#define CALCULATION_H

#include <iostream>
#include <time.h>

void noiseGenerator(int** grid, int Width = 119, int Height = 30, int density = 90, bool config_state = 0);
int** _gridInit (int Width = 119, int Height = 30);
void copyArr(int** original, int** copy, int Width = 119, int Height = 30);
int CellCount(int** original, int x, int y, int Width = 119, int Height = 30);
void iteration(int** grid, int Width = 119, int Height = 30, int iterations = -1);

#endif
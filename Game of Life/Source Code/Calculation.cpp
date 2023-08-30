#include <iostream>
#include <time.h>

void noiseGenerator(int** grid, int Width = 119, int Height = 30, int density = 90, bool config_state = 0) {
    srand(time(0));

    if (config_state) density = (rand() % (99 - 90 + 1)) + 90;

    for (int i = 0; i < Height; i++) {
        int rand_num;
        for (int j = 0; j < Width; j++) {
            rand_num = rand() % 100 + 1;

            if (rand_num < density) {
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = 0;
            }
        }
    }
}

int** _gridInit (int Width = 119, int Height = 30) {
    int** grid = new int*[Height];

    for (int i = 0; i < Height; i++) {
        grid[i] = new int[Width];

        for (int j = 0; j < Width; j++) {
            grid[i][j] = 0;
        }
    }

    return grid;
}

void copyArr(int** original, int** copy, int Width = 119, int Height = 30) {
    for (int i = 0; i < Height; i++) {
        for (int j = 0; j < Width; j++) {
            copy[i][j] = original[i][j];
        }
    }
}

int CellCount(int** original, int x, int y, int Width = 119, int Height = 30) {
    int sum = 0;
    int tempCoor[3][3];

	int y_count = y - 1;
	if (y_count < 0) y_count = Height - 1;

	for (int i = 0; i < 3; i++) {
		if (y_count >= Height) y_count %= Height;
        
        int x_count = x - 1;
		if (x_count < 0) x_count = Width - 1;

		for (int j = 0; j < 3; j++) {
			if (x_count >= Width) x_count %= Width;
            
            tempCoor[j][0] = x_count;
            tempCoor[j][1] = y_count;

            if (y_count == y && x_count == x) {
                x_count++;
                continue;
            }            
            if (!original[y_count][x_count]) sum++;

			x_count++;
		}
        y_count++;
	}

    return sum;
}

// Any live cell with fewer than two live neighbors dies, as if by underpopulation.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

// 0 White
// 1 Black

void iteration(int** grid, int Width = 119, int Height = 30, int iterations = -1) {
    int** tempArr = _gridInit(Width, Height);
    copyArr(grid, tempArr, Width, Height);

    for (int i = 0; i < Height; i++) {
        for (int j = 0; j < Width; j++) {
            int live_neighbors = CellCount(grid, j, i, Width, Height);

            if (!grid[i][j] && live_neighbors < 2) tempArr[i][j] = 1;      // Underpopulation
            else if (!grid[i][j] && (live_neighbors == 2 || live_neighbors == 3)) tempArr[i][j] = 0; // Thrive 
            else if (!grid[i][j] && live_neighbors > 3) tempArr[i][j] = 1; // Overpopulation
            else if (grid[i][j] && live_neighbors == 3) tempArr[i][j] = 0; // Reproduction
        }
    }

    copyArr(tempArr, grid, Width, Height);
}
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

// making save file for seeds
// strict render
// generation counter
// options for iteration, manual, auto

void noiseGenerator(int** grid, int Width = 119, int Height = 30, int density = 90, bool config_state = 1) {
    srand(time(0));

    if (config_state) density = (rand() % (99 - 90 + 1)) + 90;
    // std::cout << density << '\n';

    for (int i = 0; i < Height; i++) {
        int rand_num;
        for (int j = 0; j < Width; j++) {
            rand_num = rand() % 100 + 1;

            if (rand_num < density) grid[i][j] = 1;
            else grid[i][j] = 0;
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
    // std::cerr << "      CP - Width : " << Width << "\n";
    // std::cerr << "      CP - Height: " << Height << "\n";
    // _getch();

    // std::cerr << "      Breakpoint CP A\n";
    for (int i = 0; i < Height; i++) {
        // std::cerr << "      Breakpoint CP B " << i << "\n";
        for (int j = 0; j < Width; j++) {
            // std::cerr << "      Breakpoint CP C "<< j << "\n";
            copy[i][j] = original[i][j];
        }
        // std::cerr << "      Breakpoint CP D " << i << "\n\n";
    }
    // std::cerr << "      Breakpoint CP E\n";
}

int CellCount(int** original, int x, int y, int Width = 119, int Height = 30) {
    int sum = 0;

	int x_count = x - 1;
	int y_count = y - 1;
	
	if (x_count < 0) x_count = Width - 1;
	if (y_count < 0) y_count = Height - 1;
	
	for (int i = 0; i < 3; i++) {
		if (y_count >= Height) y_count %= Height;
		
		for (int j = 0; j < 3; j++) {
			if (x_count >= Width) x_count %= Width;
            if (y_count == y && x_count == x) continue;
            if (!original[y_count][x_count]) sum++;
        
			x_count++;
		} y_count++;
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
    // std::cerr << "   Breakpoint IT A\n";
    int** tempArr = _gridInit(Width, Height);
    // std::cerr << "   Breakpoint IT B\n";
    copyArr(grid, tempArr, Width, Height);
    // std::cerr << "   Breakpoint IT C\n";

    for (int i = 0; i < Height; i++) {
        // std::cerr << "   Breakpoint IT D\n";
        for (int j = 0; j < Width; j++) {
            // std::cerr << "   Breakpoint IT E\n";
            int live_neighbors = CellCount(grid, j, i, Width, Height);

            if (!grid[i][j] && live_neighbors < 2) tempArr[i][j] = 1; // Underpopulation
            else if (!grid[i][j] && (live_neighbors == 2 || live_neighbors == 3)) tempArr[i][j] = 0; // Thrive 
            else if (!grid[i][j] && live_neighbors > 3) tempArr[i][j] = 1; // Overpopulation
            else if (grid[i][j] && live_neighbors == 3) tempArr[i][j] = 0; // Reproduction
        }
        // std::cerr << "   Breakpoint IT F\n";
    }

    copyArr(tempArr, grid, Width, Height);
    // std::cerr << "   Breakpoint IT G\n";
}

void displayGrid(int** grid, int Width = 119, int Height = 30) {
    std::cout << "\n " << char(218);
    for (int i = 0; i < Width; i++) {
        std::cout << char(196);
    } std::cout << char(191) << "\n";

    // std::cout << ' ' << char(179);
    // for (int i = 0; i < Width + 2; i++) {
    //     std::cout << ' ';
    // } std::cout << char(179) << "\n";

    for (int i = 0; i < Height; i++) {
        std::cout << ' ' << char(179);
        for (int j = 0; j < Width; j++) {
            if (grid[i][j]) std::cout << ' ';
            else std::cout << char(grid[i][j] + 219);
        } std::cout << char(179) << "\n";
    }

    // std::cout << ' ' << char(179);
    // for (int i = 0; i < Width + 2; i++) {
    //     std::cout << ' ';
    // } std::cout << char(179) << "\n";

    std::cout << ' ' << char(192);
    for (int i = 0; i < Width; i++) {
        std::cout << char(196);
    } std::cout << char(217) << "\n";
}

int main() {
    int ScrnWidth = 115;
    int ScrnHeight = 26;
    int** grid = _gridInit(ScrnWidth, ScrnHeight);

    noiseGenerator(grid, ScrnWidth, ScrnHeight, 90);
    while (true) {
        system("cls");
        // std::cerr << " Breakpoint A\n";
        // std::cerr << " Breakpoint B\n";
        iteration(grid, ScrnWidth, ScrnHeight);
        // std::cerr << " Breakpoint C\n";
        displayGrid(grid, ScrnWidth, ScrnHeight);
        // std::cerr << " Breakpoint D\n";
        
        _getch();
        // std::cerr << " Breakpoint E\n\n";
    }

    return 0;
}

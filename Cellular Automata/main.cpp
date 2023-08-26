#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>

void noiseGenerator(int** grid, int density, int Width = 119, int Height = 30) {
    srand(time(0));

    for (int i = 0; i < Height; i++) {
        int rand_num;
        for (int j = 0; j < Width; j++) {        
            rand_num = rand() % 100 + 1;
            // std::cout << rand_num << ' ';

            if (rand_num < density) grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }
}

int** _gridInnit (int Width = 119, int Height = 30) {
    int** grid = new int*[Height];

    for (int i = 0; i < Height; i++) {
        grid[i] = new int[Width];

        for (int j = 0; j < Width; j++) {
            grid[i][j] = 0;
        }
    }

    return grid;
}

// void menuTest() {
//     std::cout << char(218) << char(196) << char(191) << "\n";
//     std::cout << char(192) << char(196) << char(217) << "\n";
// }

void DisplayGrid(int** grid, int Width = 119, int Height = 30) {
    std::cout << "\n " << char(218);
    for (int i = 0; i < Width + 2; i++) {
        std::cout << char(196);
    } std::cout << char(191) << "\n";

    // std::cout << ' ' << char(179);
    // for (int i = 0; i < Width + 2; i++) {
    //     std::cout << ' ';
    // } std::cout << char(179) << "\n";

    for (int i = 0; i < Height; i++) {
        std::cout << ' ' << char(179) << ' ';
        for (int j = 0; j < Width; j++) {
            if (grid[i][j]) std::cout << ' ';
            else std::cout << char(grid[i][j] + 219);
        } std::cout << ' ' << char(179) << " \n";
    }

    // std::cout << ' ' << char(179);
    // for (int i = 0; i < Width + 2; i++) {
    //     std::cout << ' ';
    // } std::cout << char(179) << "\n";

    std::cout << ' ' << char(192);
    for (int i = 0; i < Width + 2; i++) {
        std::cout << char(196);
    } std::cout << char(217) << "\n";
}

int main() {

    // 0 White
    // 1 Black
    
    int ScrnWidth = 113;
    int ScrnHeight = 26;
    int** grid = _gridInnit(ScrnWidth, ScrnHeight);

    noiseGenerator(grid, 50, ScrnWidth, ScrnHeight);
    // iteration();
    DisplayGrid(grid, ScrnWidth, ScrnHeight);
    
    // menuTest();

    _getch();

    return 0;
}
#include <iostream>

void displayGrid(int** grid, int Width = 119, int Height = 30) {
    std::cout << "\n " << char(218);
    for (int i = 0; i < Width; ++i) {
        std::cout << char(196);
    } std::cout << char(191) << "\n";

    for (int i = 0; i < Height; ++i) {
        std::cout << ' ' << char(179);
        for (int j = 0; j < Width; ++j) {
            std::cout << ' ';
            
        } std::cout << char(179) << "\n";
    }

    std::cout << ' ' << char(192);
    for (int i = 0; i < Width; ++i) {
        std::cout << char(196);
    } std::cout << char(217) << "\n";
}

void DebugMenu(int Coor_temp[][3]) {
    std::cout << ' ';
    for (int i = 0; i < 3; i++) {
        std::cout << " (" << Coor_temp[i][0] << ',' << Coor_temp[i][1] << ") ";
    } std::cout << '\n';
}
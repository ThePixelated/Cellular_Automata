#include <iostream>

void setVal(int grid[][3]) {
	int counter = 65;
	
    for (int i = 0; i < 3; i++) {
	    for (int j = 0; j < 3; j++) {
	        grid[i][j] = counter + 32;
	        counter++;
	    }
    }
}

//void printGrid(int grid[][4]) {
//	int temp_i = 0;
//	
//	std::cout << '\n';
//    for (int i = 0; i < 9; i++) {
//		int temp_j = 0;
//    	
//		if (temp_i + 1 > 4) temp_i = 0;
//    	
//		std::cout << '\t';
//	    for (int j = 0; j < 9; j++) {
//	    	if (temp_j + 1 > 4) temp_j = 0;
//	    	
//	    	
//			std::cout << grid[temp_i][temp_j] << ' ';
//			
//			temp_j++;
//	    } std::cout << "\n";
//	    
//	    temp_i++;
//    }
//}

//void correction(int grid[][4], int x, int y) {
//	if (x >= 4) x %= 4;
//	if (y >= 4) y %= 4;
//	
//	std::cout << grid[y][x] << ' ';
//}

void correction2(int grid[][3], int x, int y) {
	
}

void roundRender(int grid[][3], int x, int y) {
	int x_count = x - 1;
	int y_count = y - 1;
	
	if (x_count < 0) x_count size - 1;
	if (y_count < 0) y_count = size - 1;
	
	int area = 3;
	
	for (int i = 0; i < 3; i++) {
		if (y_count >= 3) y_count %= 3;
		
		for (int j = 0; j < 3; j++) {
			if (x_count >= 3) x_count %= 3;
			
			if (y_count == y && x_count == x) std::cout << "  ";
			else std::cout << char(grid[y_count][x_count]) << ' ';
			
			x_count++;
		} std::cout << '\n';
		
		y_count++;
	}
}

int main() {
	int grid[3][3];
	
	setVal(grid);
	
	std::cout << char(grid[-1][0]) << '\n';
	std::cout << char(grid[0][0]) << '\n';
	std::cout << char(grid[0][-1]);
	
//	roundRender(grid, 0, 0);  // Masalah kalo x v y = 0
	
//	correction(grid, 6, 21);
	
//	printGrid(grid);
	
	return 0;
}

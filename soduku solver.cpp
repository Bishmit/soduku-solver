#include<iostream>
#define SIZE 9
using namespace std;

void makeGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

bool checkRow(int grid[SIZE][SIZE], int row, int num) {
    for (int col = 0; col < SIZE; col++) {
        if (grid[row][col] == num)
            return false;
    }
    return true;
}

bool checkCol(int grid[SIZE][SIZE], int col, int num) {
    for (int row = 0; row < SIZE; row++) {
        if (grid[row][col] == num)
            return false;
    }
    return true;
}

bool checkBox(int grid[SIZE][SIZE], int startRow, int startCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + startRow][col + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool isValidPlacement(int grid[SIZE][SIZE], int row, int col, int num) {
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    return checkRow(grid, row, num) && checkCol(grid, col, num) && checkBox(grid, startRow, startCol, num);
}

bool findEmptyCell(int grid[SIZE][SIZE], int& row, int& col) {
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;
    if (!findEmptyCell(grid, row, col)) {
        return true;
    }
    for (int num = 1; num <= SIZE; num++) {
        if (isValidPlacement(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return true;
            }
            // Undo current cell for backtracking
            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int grid[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid)) {
        cout << "Sudoku solved:" << endl;
        makeGrid(grid);
    }
    else {
        cout << "No solution exists." << endl;
    }

    return 0;
}

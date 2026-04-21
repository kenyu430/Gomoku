#include "Board.h"
#include <iostream>
#include <iomanip> // 用於格式化輸出 setw()

// 構造函數：將棋盤全部填入 '.' 代表空位
Board::Board() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            grid[i][j] = '.';
}

// 顯示棋盤：包含上方與左側的座標索引（0-14）
void Board::display() const {
    // 輸出橫向座標索引
    std::cout << "   ";
    for (int i = 0; i < SIZE; i++) std::cout << std::setw(2) << i << " ";
    std::cout << "\n";

    for (int i = 0; i < SIZE; i++) {
        // 輸出左側縱向座標索引
        std::cout << std::setw(2) << i << " ";
        for (int j = 0; j < SIZE; j++) {
            std::cout << " " << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// 更新棋盤：檢查座標是否在界內且該位是否為空
bool Board::update(int r, int c, char symbol) {
    if (r >= 0 && r < SIZE && c >= 0 && c < SIZE && grid[r][c] == '.') {
        grid[r][c] = symbol;
        return true;
    }
    return false;
}

// 安全取得棋子：若超出範圍則返回空格，避免陣列越界導致當機
char Board::getPiece(int r, int c) const {
    if (r < 0 || r >= SIZE || c < 0 || c >= SIZE) return ' ';
    return grid[r][c];
}
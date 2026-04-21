#ifndef BOARD_H
#define BOARD_H

#include <vector>

/**
 * Board 類別：負責管理 $15 \times 15$ 的遊戲棋盤
 * 功能包含：初始化棋盤、顯示畫面、更新棋子狀態
 */
class Board {
public:
    static const int SIZE = 15; // 棋盤標準尺寸
    Board();                    // 構造函數：初始化棋盤為空點 '.'

    void display() const;       // 常數成員函數：負責將棋盤繪製到螢幕上

    // 嘗試在 (r, c) 落子，若成功則返回 true，位置不合法則返回 false
    bool update(int r, int c, char symbol);

    // 取得特定座標的棋子內容 (X, O 或 .)
    char getPiece(int r, int c) const;

private:
    char grid[SIZE][SIZE];      // 儲存棋盤狀態的二維陣列
};

#endif#pragma once

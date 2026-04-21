#pragma once
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Board.h"

/**
 * GameManager 類別：控制遊戲的運作邏輯
 * 負責：判斷勝負、切換玩家、處理輸入循環
 */
class GameManager {
public:
    GameManager();   // 構造函數：初始化當前玩家
    void run();      // 啟動遊戲主迴圈的方法

private:
    Board board;          // 組合 (Composition)：GameManager 擁有一張棋盤
    char currentPlayer;   // 當前玩家標記 ('X' 或 'O')

    bool checkWin(int r, int c); // 檢查最後落子的 (r, c) 是否達成五連子
    void switchPlayer();         // 切換玩家身分
};

#endif
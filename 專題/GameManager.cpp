#include "GameManager.h"
#include <iostream>

GameManager::GameManager() : currentPlayer('X') {}

// 切換玩家邏輯
void GameManager::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// 核心邏輯：勝負判定
bool GameManager::checkWin(int r, int c) {
    // 定義四個檢查方向：水平、垂直、右下斜、左下斜
    int dr[] = { 0, 1, 1, 1 };
    int dc[] = { 1, 0, 1, -1 };

    for (int i = 0; i < 4; i++) {
        int count = 1; // 當前落下的這顆棋子計為 1

        // 分別往「正向」與「反向」延伸檢查
        for (int dir = -1; dir <= 1; dir += 2) {
            for (int j = 1; j < 5; j++) {
                // 計算延伸後的座標
                int nr = r + dr[i] * j * dir;
                int nc = c + dc[i] * j * dir;

                if (board.getPiece(nr, nc) == currentPlayer) {
                    count++;
                }
                else {
                    break; // 只要斷掉就停止該方向的檢查
                }
            }
        }
        if (count >= 5) return true; // 任一方向達五顆即獲勝
    }
    return false;
}

// 遊戲主循環
void GameManager::run() {
    int r, c, moves = 0;
    while (true) {
        board.display();
        std::cout << "玩家 " << (currentPlayer == 'X' ? "1 (X)" : "2 (O)")
            << "，請輸入座標 (行 列): ";

        // 處理非法輸入（例如輸入英文字母導致 cin 失效）
        if (!(std::cin >> r >> c)) {
            std::cout << "輸入格式錯誤！請重新啟動遊戲。\n";
            break;
        }

        // 嘗試更新棋盤
        if (board.update(r, c, currentPlayer)) {
            moves++;

            // 每次成功落子就檢查是否獲勝
            if (checkWin(r, c)) {
                board.display();
                std::cout << "恭喜！玩家 " << currentPlayer << " 獲勝！\n";
                break;
            }

            // 檢查平局（棋盤填滿 225 格）
            if (moves == Board::SIZE * Board::SIZE) {
                std::cout << "棋盤已滿，平手！\n";
                break;
            }

            switchPlayer(); // 換下一位玩家
        }
        else {
            std::cout << ">> 座標無效或該位置已有棋子，請重試！ <<\n";
        }
    }
}
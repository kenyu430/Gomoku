#include "GameManager.h"

/**
 * 程式主入口
 * 採用封裝原則，main 函數中不涉及具體的遊戲邏輯
 * 僅負責建立 GameManager 物件並啟動它
 */
int main() {
    GameManager game;
    game.run();
    return 0;
}
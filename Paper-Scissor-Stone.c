// Create by Chris Tien
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 遊戲實現的函式
int game(char you, char computer)
{
    // 如果使用者和電腦選擇相同
    if (you == computer)
        return -1;

    // 如果使用者選擇石頭且電腦選擇布
    if (you == 'S' && computer == 'P')
        return 0;

    // 如果使用者選擇布且電腦選擇石頭
    else if (you == 'P' && computer == 'S')
        return 1;

    // 如果使用者選擇石頭且電腦選擇剪刀
    if (you == 'S' && computer == 'Z')
        return 1;

    // 如果使用者選擇剪刀且電腦選擇石頭
    else if (you == 'Z' && computer == 'S')
        return 0;

    // 如果使用者選擇布且電腦選擇剪刀
    if (you == 'P' && computer == 'Z')
        return 0;

    // 如果使用者選擇剪刀且電腦選擇布
    else if (you == 'Z' && computer == 'P')
        return 1;

    return -1; // 處理未預期的情況
}

// 主程式
int main()
{
    // 儲存隨機數
    int n;

    char you, computer, result;

    // 每次都選擇一個新的隨機數
    srand(time(NULL));

    // 使隨機數小於3，將其除以3
    n = rand() % 3;

    // 使用簡單的機率，3大致分為石頭、布和剪刀
    if (n == 0)
        // 'S' 代表石頭
        computer = 'S';
    else if (n == 1)
        // 'P' 代表布
        computer = 'P';
    else
        // 'Z' 代表剪刀
        computer = 'Z';

    printf("\nEnter 'S' for STONE, 'P' for PAPER, 'Z' for SCISSOR\n");

    // 使用者輸入
    scanf(" %c", &you);

    // 呼叫遊戲函式進行遊戲
    result = game(you, computer);

    if (result == -1) {
        printf("\nGame Draw!!\n");
    } else if (result == 1) {
        printf("\nYou Win!\n");
    } else { 
        printf("\nYou Lose!\n");
    }
    printf("\nYou choose : %c and Computer : %c\n", you, computer);
    printf("\n");
    return 0;
}

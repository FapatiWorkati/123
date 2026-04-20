#include <stdio.h>

#include <stdlib.h>



char board[3][3];  // Игровое поле 3x3



// Функция для инициализации поля

void initBoard() {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            board[i][j] = ' ';

        }

    }

}



// Функция для отображения поля

void printBoard() {

    printf("\n");

    printf("  1   2   3\n");

    for (int i = 0; i < 3; i++) {

        printf("%d", i + 1);

        for (int j = 0; j < 3; j++) {

            printf(" %c ", board[i][j]);

            if (j < 2) printf("|");

        }

        printf("\n");

        if (i < 2) printf("  -----------\n");

    }

    printf("\n");

}



// Функция для проверки победы

char checkWin() {

    // Проверка строк

    for (int i = 0; i < 3; i++) {

        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {

            return board[i][0];

        }

    }

    

    // Проверка столбцов

    for (int j = 0; j < 3; j++) {

        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {

            return board[0][j];

        }

    }

    

    // Проверка диагоналей

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {

        return board[0][0];

    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {

        return board[0][2];

    }

    

    return ' ';

}



// Функция для проверки ничьи

int isDraw() {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (board[i][j] == ' ') {

                return 0;  // Есть пустая клетка

            }

        }

    }

    return 1;  // Все клетки заполнены

}



// Функция для хода игрока

int playerMove(int row, int col, char symbol) {

    if (row < 0  row > 2  col < 0 || col > 2) {

        return 0;  // Неверные координаты

    }

    

    if (board[row][col] != ' ') {

        return 0;  // Клетка уже занята

    }

    

    board[row][col] = symbol;

    return 1;  // Ход успешен

}



int main() {

    int row, col;

    int currentPlayer = 1;  // 1 - X, 2 - O

    char currentSymbol;

    char winner = ' ';

    int moves = 0;

    

    initBoard();

    

    printf("=== ИГРА КРЕСТИКИ-НОЛИКИ ===\n");

    printf("Игрок 1: X\n");

    printf("Игрок 2: O\n");

    printf("Для хода введите номер строки и столбца (1-3)\n\n");

    

    while (1) {

        printBoard();

        

        // Определяем текущего игрока

        if (currentPlayer == 1) {

            currentSymbol = 'X';

            printf("Ход игрока 1 (X)\n");

        } else {

            currentSymbol = 'O';

            printf("Ход игрока 2 (O)\n");

        }

        

        // Ввод координат

        printf("Введите строку и столбец (через пробел): ");

        scanf("%d %d", &row, &col);

        

        // Преобразуем в индексы массива (1-3 -> 0-2)

        row--;

        col--;

        

        // Пытаемся сделать ход

        if (!playerMove(row, col, currentSymbol)) {

            printf("Ошибка! Неверный ход. Попробуйте снова.\n");

            continue;

        }

        

        moves++;

        

        // Проверяем победу

        winner = checkWin();

        if (winner != ' ') {

            printBoard();

            printf("Поздравляем! Игрок %d (%c) победил!\n", currentPlayer, winner);

            break;

        }

        

        // Проверяем ничью

        if (isDraw()) {

            printBoard();

            printf("Ничья! Поле заполнено.\n");

            break;

        }

        

        // Меняем игрока

        currentPlayer = (currentPlayer == 1) ? 2 : 1;

    }

    

    printf("\nИгра окончена. Спасибо за игру!\n");

    return 0;

}
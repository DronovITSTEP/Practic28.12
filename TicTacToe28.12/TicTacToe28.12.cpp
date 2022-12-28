// TicTacToe28.12.cpp

#include <iostream>

using namespace std;

// Игра "Крестики - Нолики"

#define S(X) (X) ? 'X' : 'O' // макрос для назначения символа

const int SIZE_BOARD = 3; // размер доски
char board[SIZE_BOARD][SIZE_BOARD]{ '_','_','_','_','_','_',' ',' ',' ' };


void ShowBoard(); // отображение поля
int PlayerTurn(); //ход игрока
int ComputerTurn(); // ход компьютера
void LogicGame(); // логика игры
void InicialBoard(int a, char c); // занесение в массив хода игроков

int main()
{
    setlocale(LC_ALL, "");
    LogicGame();
}

void ShowBoard() {
    for (int i = 0; i < SIZE_BOARD; i++) {
        for (int j = 0; j < SIZE_BOARD; j++) {
            if (j != 0) cout << '|';
            cout << board[i][j];
        }
        cout << endl;
    }
}

int PlayerTurn() {
    int pl;
    while (true)
    {
        cout << "Введите X и Y (слитно, без пробела) -> "; cin >> pl;
        if (pl <= 33 || pl >= 11) return pl;
        else cout << "Введено неверное значение, повторите попытку\n";
        system("cls");
    }
}
int ComputerTurn() {
    srand(time(0));
    return rand()%3*10 + rand() % 3;
}
void InicialBoard(int a, char c) {
    int x = a / 10;
    int y = a % 10;
    if (board[x][y] == 'X' || board[x][y] == 'O') {
        cout << "Нельзя. Клетка уже задана\n";
    }
    else
        board[x][y] = c;
}
void LogicGame() {
    ShowBoard();

    srand(time(0));
    int step = rand() % 2;
    char player = S(step), comp = S(!step);
    while (true)
    {
        InicialBoard((step) ? PlayerTurn() : ComputerTurn(),
                     (step)? player : comp);

        ShowBoard();
    }
}
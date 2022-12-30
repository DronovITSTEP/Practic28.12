// TicTacToe28.12.cpp

#include <iostream>
#include <algorithm>

using namespace std;

// Игра "Крестики - Нолики"

#define S(X) (X) ? 'X' : 'O' // макрос для назначения символа

const int SIZE_BOARD = 3; // размер доски
char board[SIZE_BOARD][SIZE_BOARD]{ '_','_','_','_','_','_',' ',' ',' ' };

int compStep[9]{ 00, 01, 02, 10, 11, 12, 20, 21, 22 }; // возможные ходы 


void ShowBoard(); // отображение поля
int PlayerTurn(); //ход игрока
int ComputerTurn(); // ход компьютера
void LogicGame(); // логика игры
bool InicialBoard(int a, char c); // занесение в массив хода игроков
bool IsWin(char c); // проверка выйгрыша

int main()
{
    setlocale(LC_ALL, "");
    
    srand(time(0));   
    random_shuffle(begin(compStep), end(compStep)); // перемешивет значения местами в массиве
    
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
        if ((0 < pl/10 && pl/10 < 4) && 
            (0 < pl%10 && pl%10 < 4)) 
            return pl - 11;
        else 
            cout << "Введено неверное значение, повторите попытку\n";
        //system("cls");
    }
}
int ComputerTurn() {  
    for (static int i = 0; i < 9;) {
        return compStep[i++];
    }
}
bool InicialBoard(int a, char c) {
    int x = a / 10;
    int y = a % 10;
    if (board[x][y] == 'X' || board[x][y] == 'O') {
        cout << "Нельзя. Клетка уже задана\n";
        return false;
    }
    else
        board[x][y] = c;
    return true;
}
bool IsWin(char c) {
    for (int i = 0; i < 3; i++) { // проверка по строкам
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
    }
    for (int j = 0; j < 3; j++) { // проверка по столбцам
        if (board[0][j] == c && board[1][j] == c && board[2][j] == c) return true;
    }

    // проверка по диагонали
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
    if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;

    return false;
}

void LogicGame() {
    ShowBoard();

    srand(time(0));
    int step = rand() % 2;
    char player = S(step), comp = S(!step);

    int count = 0;
    while (count <= 9)
    {
        if (!InicialBoard((count % 2) ? PlayerTurn() : ComputerTurn(),
            (count % 2) ? player : comp)) continue;

        ShowBoard();

        if (IsWin((count % 2) ? player : comp)) {           
            cout << "Победа!\n";           
            break;
        }
        count++;       
    }
    if (count > 9) cout << "Ничья!\n";
}
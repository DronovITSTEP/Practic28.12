#include <iostream>

using namespace std;

/*
Написать ф-ю, которая принимает координаты шахматной фигуры
куда нужно сходить.
Ф-я должна возвращать true или false, если этот ход возможен
  0 1 2 3 4 5 6 7	- B
0|*|_|_|_|*|_|_|_|
1|_|*|_|_|*|_|_|*|
2|_|_|*|_|*|_|*|_|
3|_|_|_|*|*|*|_|_|
4|*|*|*|*|P|*|*|*|
5|_|_|_|*|*|*|_|_|
6|_|_|*|_|*|_|*|_|
7|_|*|_|_|*|_|_|*|

|
A
*/
//для пешки
const int centerA = 4, centerB = 4;
bool IsMovePawn(int a, int b) {
	return (centerB == b && centerA == a - 1) ? true : false;
}
//для слона
bool IsMoveElephant(int a, int b) {
	return (abs(centerA - a) == abs(centerB - b)) ? true : false;
}
//для ладьи
bool IsMoveRook(int a, int b) {
	return (centerA == a || centerB == b)? true : false;
}
//ход коня
bool IsMoveHorse(int a, int b) {
	return 
		(( abs(centerA - a) == 1 && abs (centerB - b) == 2) || 
		 ( abs(centerA - a) == 2 && abs (centerB - b) == 1)) ? true : false;
}
//ход королевы
bool IsMoveQueen(int a, int b) {
	return (IsMoveElephant(a, b) || IsMoveRook(a, b))  ? true : false;
}



int main()
{
	/*
	srand(time(0));

	// генерация чисел от 5 до 23
	int arr[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = 5 + rand() % 18; // 5 - 23
		cout << arr[i] << " ";
	}

	cout << endl;

	//генерация вещественных чисел от 2.0 до 5.0
	double arrDouble[5];
	for (int i = 0; i < 5; i++) {
		arrDouble[i] = 2 + rand() % 3 + (double)(rand() % 100) / 100;
		cout << arrDouble[i] << " ";
	}
	cout << endl;

	//генерация целы чисел от -10 до 10
	int arrInt[10];
	for (int i = 0; i < 10; i++) {
		arrInt[i] = rand() % 10 - rand() % 10;
		cout << arrInt[i] << " ";
	}
	*/


}

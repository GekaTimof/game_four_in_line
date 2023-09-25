#include <iostream>
#include "field.h"

using namespace std;


Field::Field(bool isRedFirst){
	clear(isRedFirst);
}

// вывод игрового поля
void Field::print() const {
	for (int j = 0; j < FIELD_HEIGHT; j++)
	{
		cout << '\n';
		for (int i = 0; i < FIELD_WIDTH; i++)
			cout << cells[i][FIELD_HEIGHT - 1 - j] << " ";
	}
}

// показать результат
void Field::printResult() const {
	cout << " Игра закончена \n";
	if (winner) {
		if (winner == 1) 
			cout << "Победитель - " << "RED";
		else
			cout << "Победитель - " << "YELLOW";

	}
	else {
		cout << "Победитель отсутствует";
	}
}


// очистка поля
void Field::clear(bool isRedFirst){
	isRedTurn = isRedFirst;
	winner = EMPTY;
	for (int i = 0; i < FIELD_WIDTH; i++)
		for (int j = 0; j < FIELD_HEIGHT; j++)
			cells[i][j] = EMPTY;
}

// чей сейчас ход
bool Field::isRedTurnNow() const {
	if (isRedTurn == RED) {
		return true;
	}
	else {
		return false;
	}
}

// осуществление хода
bool Field::makeTurn(int column){
	// если нельзя сделать ход
	if (winner != EMPTY || column < 1 || column > FIELD_WIDTH)
		return false;

	int i = column - 1;
	for (int j = 0; j < FIELD_HEIGHT; j++)
		if (cells[i][j] == EMPTY){
			cells[i][j] = isRedTurn ? RED : YELLOW;
			checkWinner(); // Победа?
			isRedTurn = !isRedTurn;
			return true;
		}
	return false;
}

// Определение победителя
const int DIR_NUMBER = 4;
const int di[] = { 1, 0, 1, 1 };
const int dj[] = { 0, 1, -1, 1 };
const int WIN_LENGTH = 4;
void Field::checkWinner()
{
	for (int i = 0; i < FIELD_WIDTH; i++)
		for (int j = 0; j < FIELD_HEIGHT; j++)
		{
			Cell start = cells[i][j];
			if (start == EMPTY) continue;
			for (int dir = 0; dir < DIR_NUMBER; dir++)
			{
				int length = 0, iline = i, jline = j;
				while (++length < WIN_LENGTH)
				{
					iline += di[dir];
					jline += dj[dir];
					if (iline < 0 || iline >= FIELD_WIDTH ||
						jline < 0 || jline >= FIELD_HEIGHT)
						break;
					if (cells[iline][jline] != start) break;
				}
				if (length == WIN_LENGTH)
				{
					winner = start;
					return;
				}
			}
		}
}
// проверка окончания игры
bool Field::isOver() const
{
	if (winner != EMPTY)
		return true;
	for (int i = 0; i < FIELD_WIDTH; i++)
		for (int j = 0; j < FIELD_HEIGHT; j++)
			// Если хоть одна ячейка свободна,
			// игра не окончена
			if (cells[i][j] == EMPTY)
				return false;
	// Все ячейки заняты
	return true;
}




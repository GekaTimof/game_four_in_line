#ifndef _FIELD
#define _FIELD

#include <iostream>
using namespace std;
// ширина пол€
const int FIELD_WIDTH = 7;
// высота пол€
const int FIELD_HEIGHT = 6;


// класс €чейки
enum Cell {
	EMPTY,
	RED,
	YELLOW
};

// класс игрового пол€
class Field{
private:
	// ƒвумерный массив дл€
	// хранени€ игрового пол€
	Cell cells[FIELD_WIDTH][FIELD_HEIGHT];
	// ќчередь хода
	bool isRedTurn;
	//  то на данный момент выиграл
	Cell winner;
	// ќпределение победител€
	void checkWinner();


public:
	// ход играка
	Field(bool isRedFirst);
	// очистка пол€
	void clear(bool isRedFirst);
	// добалени€ элемента в колонку
	bool makeTurn(int column);
	//// определение победител€
	//bool isWon(bool red) const;
	// определение завершени€ игры
	bool isOver() const;
	// 
	Cell getCell(int i, int j) const;
	// чей сейчас ход
	bool isRedTurnNow() const;
	// вывод игрового пол€
	void print() const;
	// показать результат
	void printResult() const;

};



#endif
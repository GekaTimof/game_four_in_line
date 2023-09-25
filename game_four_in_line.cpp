#include <iostream>
#include <string>
#include "field.h"

using namespace std;
// Start program hear
int main(void)
{
	setlocale(LC_ALL, "Russian");
	Field field(true);
	
	// пока игра не закончена
	while (!field.isOver()){
		field.print();
		cout << "Ходит " <<
			(field.isRedTurnNow() ? "красный" : "желтый") <<
			" игрок, введите ход (1-7)" << endl;
		// принимаем в какую колонку ходим
		int column; cin >> column;
		// делаем ход в нужную колонку
		field.makeTurn(column);
	}
	field.printResult();
	return 0;
}
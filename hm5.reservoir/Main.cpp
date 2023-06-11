#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Reservoir.h"
#include "Globals.h"
#include "Logic.h"
#include "Display.h"

using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	int size = 0;
	Reservoir* reservoir = new Reservoir[size];

    char filename[MAX_PATH] = "save.bin";
    FILE* file = nullptr;
    LogicReadData(file, reservoir, filename, size);

	char select = 0;

	const char* menu[]
	{
		"Додати водойму     ",
		"Вивести список     ",
		"Видалити водойму   ",
		"Редагувати         ",
		"Вихід              "
	};

	while (true) {

		DisplayMenu(menu, MENU_ROW, select);

		char action = _getch();
		if (action == 0 || action == 224)
			action = _getch();

		switch (action) {

		case UP:
			select = (select - 1 + MENU_ROW) % MENU_ROW;
			break;

		case DOWN:
			select = (select + 1) % MENU_ROW;
			break;

		case ENTER:
			switch (select) {

			case ADD:
				DisplayAdd(reservoir, size);
				break;

			case PRINT:
				DisplayPrint(reservoir, size);
				break;

			case REMOVE:
				DisplayRemove(reservoir, size);
				break;

			case EDIT:
				DisplayEdit(reservoir, size);
				break;

			case EXIT:
				LogicSaveData(file, reservoir, filename, size);
				delete[]reservoir;
				return 0;
			}
			break;

		case ESC:
			LogicSaveData(file, reservoir, filename, size);
			delete[]reservoir;
			return 0;
		}
	}
        
    return 0;
}
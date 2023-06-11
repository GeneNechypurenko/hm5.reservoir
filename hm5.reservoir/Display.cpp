#include "Display.h"

void DisplayMenu(const char* menu[], int row, int select) {

	char marker = 149;
	system("cls");

	for (int i = 0; i < row; i++) {

		if (i == select) {

			cout << " " << marker << " ";
			cout << menu[i] << endl;
		}

		else {

			cout << "   ";
			cout << menu[i] << endl;
		}
	}
}

void DisplayAdd(Reservoir*& reservoir, int& size) {

	system("cls");

	LogicCleanBuffer();
	LogicAdd(reservoir, size);

	system("pause");
}

void DisplayPrint(const Reservoir* reservoir, int size) {

	system("cls");

	if (size != 0) {

		for (int i = 0; i < size; i++) {

			cout << "-- ВОДОЙМА №[" << i + 1 << "] --" << endl;
			reservoir[i].Print();
			cout << "___________________" << endl;
		}
	}

	else
		cout << "список пустий.." << endl << endl;

	system("pause");
}

void DisplayRemove(Reservoir*& reservoir, int& size) {

	system("cls");

	if (size != 0) {

		DisplayPrint(reservoir, size);

		system("cls");
		int index;
		cout << "введіть номер водойми для видалення: ";
		LogicSafeInput(index, 1, size);
		index -= 1;

		LogicRemove(reservoir, size, index);
	}

	else
		cout << "список пустий.." << endl << endl;

	system("pause");
}

void DisplayEdit(Reservoir*& reservoir, int size) {

	system("cls");

	if (size != 0) {

		DisplayPrint(reservoir, size);

		system("cls");
		int index;
		cout << "введіть номер водойми для редагування: ";
		LogicSafeInput(index, 1, size);
		index -= 1;

		LogicCleanBuffer();
		LogicInputData(reservoir, index);
	}

	else
		cout << "список пустий.." << endl << endl;

	system("pause");
}
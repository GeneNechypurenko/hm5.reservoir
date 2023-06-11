#include "Logic.h"

void LogicCleanBuffer() {

    if (cin.rdbuf()->in_avail() != 0)    {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
}

void LogicSafeInput(int& value, int min, int max) {

    while (!(cin >> value) || value < min || value > max) {
        cout << "помилка, невірно задане значення.. спробуйте знову: ";
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
}

void LogicInputData(Reservoir*& reservoir, int index) {

    char type[20];
    int width;
    int length;
    int depth;

    cout << "введіть тип водойми: ";
    cin.getline(type, 20);
    reservoir[index].SetType(type);

    cout << "введіть ширину водойми: ";
    LogicSafeInput(width, 1, 5000);
    reservoir[index].SetWidth(width);

    cout << "введіть довжину водойми: ";
    LogicSafeInput(length, 1, 5000);
    reservoir[index].SetLength(length);

    cout << "введіть глибину водойми: ";
    LogicSafeInput(depth, 1, 5000);
    reservoir[index].SetDepth(depth);
}

void LogicAdd(Reservoir*& reservoir, int& size) {

	Reservoir* temp = new Reservoir[size + 1];

    for (int i = 0; i < size; i++)
        temp[i] = reservoir[i];

    LogicInputData(temp, size);

    delete[] reservoir;
    reservoir = temp;
    size++;
}

void LogicRemove(Reservoir*& reservoir, int& size, int index) {

    Reservoir* temp = new Reservoir[size];
    int j = 0;

    for (int i = 0; i < size; i++) 
        if (i != index) {
            temp[j] = reservoir[i];
            j++;
        }

    delete[] reservoir;
    reservoir = temp;
    size--;
}

void LogicSaveData(FILE* file, Reservoir*& reservoir, const char* filename, int size) {

    const int type_size = 20;

    fopen_s(&file, filename, "wb");

    if (file == nullptr) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    fwrite(&size, sizeof(size), 1, file);

    for (int i = 0; i < size; i++) {

        const char* type = reservoir[i].GetType();
        int width = reservoir[i].GetWidth();
        int length = reservoir[i].GetLength();
        int depth = reservoir[i].GetDepth();

        fwrite(type, sizeof(char), type_size, file);
        fwrite(&width, sizeof(width), 1, file);
        fwrite(&length, sizeof(length), 1, file);
        fwrite(&depth, sizeof(depth), 1, file);
    }

    fclose(file);
}


void LogicReadData(FILE* file, Reservoir*& reservoir, const char* filename, int& size) {

    const int type_size = 20;

    fopen_s(&file, filename, "rb");

    if (file == nullptr) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    fread(&size, sizeof(size), 1, file);

    Reservoir* data = new Reservoir[size];

    for (int i = 0; i < size; i++) {
        char type[type_size];
        int width, length, depth;

        fread(type, sizeof(char), type_size, file);
        fread(&width, sizeof(width), 1, file);
        fread(&length, sizeof(length), 1, file);
        fread(&depth, sizeof(depth), 1, file);

        data[i].SetType(type);
        data[i].SetWidth(width);
        data[i].SetLength(length);
        data[i].SetDepth(depth);
    }

    fclose(file);

    reservoir = data;
}

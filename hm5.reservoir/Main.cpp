#include <iostream>
#include <windows.h>

#include "Reservoir.h"

using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\n-----------------orinal-----------------\n";

    Reservoir reservoir[2] = {

        Reservoir("Море", 100.0, 200.0, 50.0),
        Reservoir("Озеро", 50.0, 100.0, 20.0)
    };

    for (int i = 0; i < 2; i++) 
        reservoir[i].Print();

    if (reservoir[0] == reservoir[1]) 
        cout << "Водойми однакового типу" << endl;
    else 
        cout << "Водойми різного типу" << endl;
    

    cout << "\n----------------- copy -----------------\n";

    reservoir[1] = reservoir[0];

    for (int i = 0; i < 2; i++)
        reservoir[i].Print();

    if (reservoir[0] == reservoir[1])
        cout << "Водойми однакового типу" << endl;
    else
        cout << "Водойми різного типу" << endl;
        
    return 0;
}
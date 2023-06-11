#pragma once
#include "Reservoir.h"
#include "Logic.h"

void DisplayMenu(const char* menu[], int row, int select);

void DisplayAdd(Reservoir*& reservoir, int& size);
void DisplayPrint(const Reservoir* reservoir, int size);
void DisplayRemove(Reservoir*& reservoir, int& size);
void DisplayEdit(Reservoir*& reservoir, int size);
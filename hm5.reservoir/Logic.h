#pragma once
#include "Reservoir.h"

void LogicCleanBuffer();
void LogicSafeInput(int& value, int min, int max);
void LogicInputData(Reservoir*& reservoir, int index);

void LogicAdd(Reservoir*& reservoir, int& size);
void LogicRemove(Reservoir*& reservoir, int& size, int index);

void LogicSaveData(FILE* file, Reservoir*& reservoir, const char* filename, int size);
void LogicReadData(FILE* file, Reservoir*& reservoir, const char* filename, int& size);
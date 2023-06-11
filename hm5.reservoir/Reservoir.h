#pragma once
#include <iostream>

using namespace std;

class Reservoir {

    char* type;
    int width;
    int length;
    int depth;

public:
    explicit Reservoir();

    Reservoir(const Reservoir& object) = delete;

    ~Reservoir();

    Reservoir& operator=(const Reservoir& object);
    bool operator==(const Reservoir& object) const;

    void SetType(const char* type);
    void SetWidth(int width);
    void SetLength(int length);
    void SetDepth(int depth);

    const char* GetType() const;
    int GetWidth() const;
    int GetLength() const;
    int GetDepth() const;

    int Volume() const;
    int Area() const;
    void Print() const;
};
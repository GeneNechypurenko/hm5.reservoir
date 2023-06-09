#pragma once
#include <iostream>

using namespace std;

class Reservoir {

    char* type;
    long width;
    long length;
    long depth;

public:
    explicit Reservoir(const char* type = "", long width = 0, long length = 0, long depth = 0);

    Reservoir(const Reservoir& object);

    ~Reservoir();

    Reservoir& operator=(const Reservoir& object);
    bool operator==(const Reservoir& object) const;

    void SetType(const char* type);
    void SetWidth(long width);
    void SetLength(long length);
    void SetDepth(long depth);

    const char* GetType() const;
    long GetWidth() const;
    long GetLength() const;
    long GetDepth() const;

    long Volume() const;
    long Area() const;
    void Print() const;
};
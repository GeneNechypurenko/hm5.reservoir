#include "Reservoir.h"

Reservoir::Reservoir(const char* type, long width, long length, long depth)    
    : width(width), length(length), depth(depth) {

    this->type = new char[strlen(type) + 1];
    strcpy_s(this->type, strlen(type) + 1, type);
}

Reservoir::Reservoir(const Reservoir& object)
    : width(object.width), length(object.length), depth(object.depth) {

    this->type = new char[strlen(object.type) + 1];
    strcpy_s(this->type, strlen(object.type) + 1, object.type);
}

Reservoir::~Reservoir() {

    delete[] type;
}

bool Reservoir::operator==(const Reservoir& object) const {

    if (strcmp(this->type, object.type) == 0)
        return true;

    return false;
}

Reservoir& Reservoir::operator=(const Reservoir& object) {

    width = object.width;
    length = object.length;
    depth = object.depth;

    delete[] type;
    type = new char[strlen(object.type) + 1];
    strcpy_s(type, strlen(object.type) + 1, object.type);

    return *this;
}

void Reservoir::SetType(const char* type) {

    delete[] this->type;
    this->type = new char[strlen(type) + 1];
    strcpy_s(this->type, strlen(type) + 1, type);
}

void Reservoir::SetWidth(long width) {

    this->width = width;
}

void Reservoir::SetLength(long length) {

    this->length = length;
}

void Reservoir::SetDepth(long depth) {

    this->depth = depth;
}

const char* Reservoir::GetType() const {

    return type;
}

long Reservoir::GetWidth() const {

    return width;
}

long Reservoir::GetLength() const {

    return length;
}

long Reservoir::GetDepth() const {

    return depth;
}

long Reservoir::Volume() const {

    return width * length * depth;
}

long Reservoir::Area() const {

    return width * length;
}

void Reservoir::Print() const {

    cout << "Тип водойми: " << type << std::endl;
    cout << "Ширина водойми: " << width << std::endl;
    cout << "Довжина водойми: " << length << std::endl;
    cout << "Глибина водойми: " << depth << std::endl;
    cout << "Об'єм водойми: " << Volume() << std::endl;
    cout << "Площина водойми: " << Area() << std::endl;
    cout << endl;
}

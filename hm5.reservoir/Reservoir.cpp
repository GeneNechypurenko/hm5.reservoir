#include "Reservoir.h"

Reservoir::Reservoir()    
    : type(nullptr), width(0), length(0), depth(0) {}

//Reservoir::Reservoir(const Reservoir& object)
//    : width(object.width), length(object.length), depth(object.depth) {
//
//    this->type = new char[strlen(object.type) + 1];
//    strcpy_s(this->type, strlen(object.type) + 1, object.type);
//}

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

    if (this->type != nullptr)
        delete[] this->type;

    type = new char[strlen(object.type) + 1];
    strcpy_s(type, strlen(object.type) + 1, object.type);

    return *this;
}

void Reservoir::SetType(const char* type) {

    if(this->type != nullptr)
    delete[] this->type;

    this->type = new char[strlen(type) + 1];
    strcpy_s(this->type, strlen(type) + 1, type);
}

void Reservoir::SetWidth(int width) {

    this->width = width;
}

void Reservoir::SetLength(int length) {

    this->length = length;
}

void Reservoir::SetDepth(int depth) {

    this->depth = depth;
}

const char* Reservoir::GetType() const {

    return type;
}

int Reservoir::GetWidth() const {

    return width;
}

int Reservoir::GetLength() const {

    return length;
}

int Reservoir::GetDepth() const {

    return depth;
}

int Reservoir::Volume() const {

    return width * length * depth;
}

int Reservoir::Area() const {

    return width * length;
}

void Reservoir::Print() const {

    cout << "Тип водойми: " << type << endl;
    cout << "Ширина водойми: " << width << endl;
    cout << "Довжина водойми: " << length << endl;
    cout << "Глибина водойми: " << depth << endl;
    cout << "Об'єм водойми: " << Volume() << endl;
    cout << "Площина водойми: " << Area() << endl;
}

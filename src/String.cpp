#include "String.h"

String::~String()
{
    //dtor
}

String::String(const String& other)
{
    //copy ctor
}

String& String::operator=(const String& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

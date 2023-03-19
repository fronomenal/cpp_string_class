#ifndef STRING_H
#define STRING_H

#include <iostream>

class String{

friend std::istream& operator>>(std::istream& is, String& rhs);
friend std::ostream& operator<<(std::ostream& os, String& rhs);

private:
    char* strref;
    size_t len;
    size_t i{0}; // member index for looping

    //methods
    size_t strlen(const char* str);

public:
    //Constructors
    String() : strref{nullptr}, len{0} {}
    String(const char* in);
    ~String();
    String(const String& source);
    String(String&& source);

    //Getters
    unsigned short getLength() const {return len;}

    //Over loaders
    String& operator=(const String& rhs);
    // concatenates the two strings
    String& operator+(const String& rhs);
    String& operator+=(const String& rhs);
    String& operator+(const char* rhs);
    String& operator+=(const char* rhs);
    // scales the string by the multiplication number specified
    String& operator*(const int& rhs);
    String& operator*=(const int& rhs);

    // compares individual characters
    bool operator!=(const String& rhs);
    bool operator==(const String& rhs);
    // sums ASCII code points and compares them
    bool operator<(const String& rhs);
    bool operator>(const String& rhs);

    // convert lower case chars to upper case
    String& operator++();
    String& operator++(int);
    // convert upper case chars to lower case
    String& operator--();
    String& operator--(int);



};

#endif // STRING_H

#include "String.h"

String::String(const char* in) : strref{nullptr}, len{0}{

    if(in==nullptr){
        len = 0;
        strref = new char[1];
        strref[0] = 0;
        return;
    }

    len = strlen(in);

    strref = new char[len+1];
    for(i=0;;i++){
        if(i==len){
            strref[i]=0;
            break;
        }
        strref[i]=in[i];
    }
}
String::~String(){
    delete [] strref;
}

// copy
String::String(const String& source) : len{source.len}{
    strref = new char[len+1];
    for(i=0;i<=len;i++)
        strref[i] = source.strref[i];
}

// move
String::String(String&& source) : len{source.len}{
    strref = source.strref;
    source.strref = nullptr;
}

size_t String::strlen(const char* str){
    for(i=0;;i++){
        if(str[i]==0){
            return i;
        }
    }
}

String& String::operator=(const String& rhs) {
    if(this==&rhs) return *this;
    len = rhs.len;
    strref = new char[len+1];
    for(i=0;i<=len;i++)
        strref[i] = rhs.strref[i];
    return *this;
}

String& String::operator+(const String& rhs){
    size_t tmplen = len + rhs.len;
    char tmpstr[tmplen+1];
    for(i=0;i<len;i++)
        tmpstr[i]=strref[i];
    for(;i<=tmplen;i++)
        tmpstr[i]=rhs.strref[i-len];
    String* tmp = new String{tmpstr};

    return *tmp;
}
String& String::operator+=(const String& rhs){
    return *this = operator+(rhs);
}

String& String::operator+(const char* rhs){
    size_t tmplen = len + strlen(rhs);
    char tmpstr[tmplen+1];
    for(i=0;i<len;i++)
        tmpstr[i]=strref[i];
    for(;i<=tmplen;i++)
        tmpstr[i]=rhs[i-len];
    String* tmp = new String{tmpstr};

    return *tmp;
}

String& String::operator+=(const char* rhs){
    return *this = operator+(rhs);
}

String& String::operator*(const int& rhs){
    if(rhs<=0) return *this;
    size_t count{0};
    char* tmpStr = new char[len*rhs+1];
    while(count<rhs*len){
        for(i=0;i<len;i++){
            tmpStr[i+count] = strref[i];
        }
        count+=len;
    }
    tmpStr[len*rhs] = 0;
    String* tmp = new String{tmpStr};
    delete [] tmpStr;
    return *tmp;
}

String& String::operator*=(const int& rhs){
    return *this = operator*(rhs);;
}

bool String::operator!=(const String& rhs){
    if(len!=rhs.len) return true;
    for(i=0;i<len;i++)
        if(strref[i]!=rhs.strref[i]) return true;
    return false;

}
bool String::operator==(const String& rhs){
    return !operator!=(rhs);
}
bool String::operator<(const String& rhs){
    int rhssum{0},sum{0};
    for(i=0;i<len;i++)
        sum+=static_cast<int>(strref[i]);
    for(i=0;i<rhs.len;i++)
        rhssum+=static_cast<int>(rhs.strref[i]);
    return sum<rhssum;
}
bool String::operator>(const String& rhs){
    return !operator<(rhs);
}

String& String::operator++(){
    for(i=0;i<len;i++)
        if(strref[i]>=97 && strref[i]<=122) strref[i]-=32;
    return *this;
}
String& String::operator++(int){
    String* cpy = new String;
    *cpy = *this;
    operator++();
    return *cpy;
}
String& String::operator--(){
    for(i=0;i<len;i++)
        if(strref[i]>=65 && strref[i]<=90) strref[i]+=32;
    return *this;
}
String& String::operator--(int){
    String* cpy = new String;
    *cpy = *this;
    operator--();
    return *cpy;
}

std::istream& operator>>(std::istream& is, String& rhs){
    char* temp{new char[300]};
    is>> temp;
    rhs = String{temp};
    delete [] temp;
    return is;
    }

std::ostream& operator<<(std::ostream& os, String& rhs){
    os<< rhs.strref;
    return os;
    }

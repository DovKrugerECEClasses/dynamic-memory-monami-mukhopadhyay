/* 
Author: Xingyuan Guo & Monami Mukhopadhyay
Program: String
*/
#include "String.hh"

using namespace std;

String::String() : len(0), capacity(0), s(nullptr) {}

String::String(const char str[]) : len(strlen(str)), capacity(strlen(str)), s(new char[len]) {
    //void * memcpy ( void * destination, const void * source, size_t num );
    memcpy(s, str, len);
}

String String::operator+=(const String &newString) {
    this->checkGrow(newString.len);
    uint32_t new_len = this->len + newString.len;
    char *str = new char[new_len];
    memcpy(str, this->s, this->len); // copy over the orig content
    memcpy(str + newString.len, newString.s, newString.len);
    // could do this also
    //    for (auto i = 0; i < newString.len; i++)
    //        str[this->len + i] = newString.s[i];
    this->len = new_len;
    this->s = str;
    //std::cout << "cap " << capacity << endl;
    return *this;
}

String::String(const char str[], uint32_t mult) : len(strlen(str) * mult), s(new char[len]) {
    checkGrow(len);
    uint32_t strsize = strlen(str);
    int c = 0;
    for (auto j = 0; j < mult; j++)
        for (auto i = 0; i < strsize; i++, c++)
            s[c] = str[i];
}

//copy constructor
String::String(const String &orig) : len(orig.len), capacity(orig.capacity), s(new char[len]) {
    for (auto i = 0; i < len; i++)
        s[i] = orig.s[i];
}

String &String::operator=(const String &orig) {
    String copy(orig);
    len = orig.len;
    capacity = orig.capacity;
    swap(s, copy.s);
    return *this;
}

String String::substring(uint32_t start, uint32_t len) {
    char *str = new char[len + 1];
    for (auto i = 0; i < len; i++)
        str[i] = this->s[start + i];
    return String(str);
}

char String::operator[](const uint32_t pos) const {
    try {
        if (pos >= len)
            throw 1;
        return s[pos];
    }
    catch (exception &e) {
        cout << "Standard exception: " << e.what() << endl;
    }
}

char &String::operator[](uint32_t pos) { return s[pos]; }

void String::replace(char ori, char repl) {
    for (auto i = 0; i < len; i++)
        if (s[i] == ori)
            s[i] = repl;
}

uint32_t String::length() const { return this->len; }

String String::operator+(const String &newString) {

    this->checkGrow(newString.len);
    uint32_t new_len = this->len + newString.len;
    char *str = new char[new_len];
    memcpy(str, this->s, this->len); // copy over the orig content
    for (auto i = 0; i < newString.len; i++)
        str[this->len + i] = newString.s[i];
    this->len = new_len;
    this->s = str;
    //std::cout << "cap " << capacity << endl;
    return *this;
}

void String::insert(uint32_t pos, const String &str) {
    checkGrow(str.len);
    // void * memmove ( void * destination, const void * source, size_t num );
    memmove(s + pos + str.len, s + pos, len);
    memcpy(s + pos, str.s, str.len);
}




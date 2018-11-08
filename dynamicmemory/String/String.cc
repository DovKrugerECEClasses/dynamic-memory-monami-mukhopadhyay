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
    for (uint32_t i = 0; i < newString.len; i++)
        str[this->len + i] = newString.s[i];
    this->len= new_len;
    this->s = str;
    std::cout << "cap " << capacity << endl;
    return *this;
}


String::String(const char str[], uint32_t mult) {

}

//copy constructor
String::String(const String &orig) {

}

String &String::operator=(const String &orig) {

}

char String::operator[](const uint32_t pos) const {

}

char &String::operator[](uint32_t pos) {

}








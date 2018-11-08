#include <iostream>
#include <cstring>

class String {
private:
    uint32_t capacity; // the max capacity of the string
    uint32_t len; // the actual length of the string
    char *s;

    void checkGrow(uint32_t newLen) {
        if (newLen > this->capacity) { //allocate double the size of newLen
            //const char *old = s; // commented out because work is done in cpp file
            this->capacity = 2 * newLen;
            //memcpy(s, old, capacity);
        }
    }

public:
    String();

    String(const char str[]);

    String operator+=(const String &s); //append to the end

    String(const char str[], uint32_t mult);

    ~String() { delete[] s; }

    //copy constructor
    String(const String &orig);

    String &operator=(const String &orig);

    String substring(uint32_t start, uint32_t len);

    char operator[](const uint32_t pos) const;

    char &operator[](uint32_t pos);

    friend std::ostream &operator<<(std::ostream &os, const String &str) {
        for (uint32_t i = 0; i < str.len; ++i)
            os << str.s[i];
        return os;
    }

    void replace(char ori, char repl);

    uint32_t length() const;

    //void insert(uint32_t pos, const String &str)();


    String operator+(const String& newString);

};


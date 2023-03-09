#include <iostream>

using namespace std;


int strlen(char* str) {
    int counter = 0;

    while (str[counter] != '\0') {
        counter++;
    }

    return counter;
}

class String {
private:
    char* str = nullptr;
    int length;

    void copyChars(char*& to, char* from) {
        int length = strlen(from);

        to = new char[length + 1];

        for (int i = 0; i < length; i++) {
            to[i] = from[i];
        }

        to[length] = '\0';
    }

public:
    String() {

    }

    String(char* str) {
        this->length = strlen(str);

        this->copyChars(this->str, str);
    }

    ~String() {
        delete[] this->str;
    }

    String& operator=(const String& other) {
        if (&this->str == &other.str) return *this;

        delete[] this->str;

        this->copyChars(this->str, other.str);

        this->length = other.length;

        return *this;
    }

    String operator+(const String& other) {
        String newStr;

        int length = this->length + other.length;

        newStr.str = new char[length + 1];

        for (int i = 0; i < this->length; i++) {
            newStr.str[i] = this->str[i];
        }

        for (int i = 0; i < other.length; i++) {
            newStr.str[i + this->length] = other.str[i];
        }

        newStr.str[length] = '\0';
        newStr.length = length;

        return newStr;
    }

    String(const String& other) {
        this->copyChars(this->str, other.str);

        this->length = other.length;
    }

    friend ostream& operator<<(ostream& os, const String& str);

    int Length() {
        return this->length;
    }
};

ostream& operator<<(ostream& os, const String& str)
{
    os << str.str;
    return os;
}

int main() {
    String str = "Hello";
    String str2 = " World";

    String str3 = str + str2;

    cout << str3 << endl;
}

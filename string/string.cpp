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
    char* str;
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
    int Size() {
      return this->length;
    }

    String() {
      this->str = nullptr;
      this->length = 0;
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

    bool operator==(const String& other) {
      if (&this->str == &other.str) return true;
      if (this->length != other.length) return false;

      for (int i = 0; i < this->length; ++i) {
        if (this->str[i] != other.str[i]) return false;
      }

      return true;
    }

    bool operator!=(const String& other) {
      return !this->operator==(other);
    }

    char& operator[](int index) {
      if (index >= this->length || index < 0) throw std::invalid_argument("Out Of Range Exception");

      return this->str[index];
    }

    String(const String& other) {
      this->length = other.length;
      this->copyChars(this->str, other.str);
    }

    String(String&& other) {
      this->length = other.length;
      this->str = other.str;

      other.str = nullptr;
    }

    friend ostream& operator<<(ostream& os, const String& str);

    int Length() {
      return this->length;
    }
};

ostream& operator<<(ostream& os, const String& str) {
  os << str.str;
  return os;
}

int main() {
  String str = "Hello";
  String str2 = " World";

  String test;

  test = str + str2;

  cout << test << endl;
}

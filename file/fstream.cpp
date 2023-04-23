#include <Windows.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string filePath = filesystem::current_path().parent_path().string() + "/file/";
string fileName = "example.txt";

int main() {
  fstream fs;

  fs.open(filePath + fileName, fstream::in | fstream::out | ofstream::trunc);

  if (!fs.is_open()) {
    cout << "Could not open the file" << endl;
    return 1;
  }

  SetConsoleCP(1251);
  fs << "Тестовое сообщение" << endl;

  SetConsoleCP(866);
  fs << "Test message" << endl;

  fs.seekg(0, fstream::beg); // return read (get) pointer to the start of stream

  string str;
  while (getline(fs, str)) {
    cout << str << endl;
  }

  fs.close();

  return 0;
}
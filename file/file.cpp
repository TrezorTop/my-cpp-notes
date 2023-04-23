#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string filePath = filesystem::current_path().parent_path().string() + "/file/";
string fileName = "example.txt";

void writeFile() {
  ofstream fout;

  fout.open(filePath + fileName, ofstream::app);

  if (!fout.is_open()) {
    cout << "Could not open file" << endl;
    return;
  }

  fout << "Hello, world!" << endl;

  string input;
  getline(cin, input);

  fout << input << endl;

  fout.close();
}

void readFile() {
  ifstream fin(filePath + fileName);

  if (!fin.is_open()) {
    cout << "Could not open file" << endl;
    return;
  }

  string str;
  while (getline(fin, str)) {
    cout << str << endl;
  }

  fin.close();
}

int main() {
  //    writeFile();
  readFile();

  return 0;
}
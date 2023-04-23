#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string filePath = filesystem::current_path().parent_path().string() + "/file/";
string fileName = "example.txt";

class Point {
public:
  Point() { this->x = this->y = this->z = 0; }

  Point(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

private:
  int x, y, z;

  friend ostream &operator<<(ostream &os, const Point &point);

  friend istream &operator>>(istream &is, Point &point);
};

ostream &operator<<(ostream &os, const Point &point) {
  return os << point.x << '\t' << point.y << '\t' << point.z;
}

istream &operator>>(istream &is, Point &point) {
  is >> point.x >> point.y >> point.z;

  return is;
}

void writeBinaryFile() {
  Point point(3, 5, 6);
  Point secondPoint(10, 52, -24);

  ofstream fout;
  fout.open(filePath + fileName);

  if (!fout.is_open()) {
    cout << "Could not open file" << endl;
    return;
  }

  //    fout.write((char*) &point, sizeof(Point));
  //    fout.write((char*) &secondPoint, sizeof(Point));
  fout << point << endl;
  fout << secondPoint << endl;

  fout.close();
}

void readBinaryFile() {
  Point point;

  ifstream fin;
  fin.open(filePath + fileName);

  if (!fin.is_open()) {
    cout << "Could not open file" << endl;
    return;
  }

  while (true) {
    fin >> point;
    if (fin.eof())
      break;
    cout << point << endl;
  }

  fin.close();
}

int main() {
  writeBinaryFile();
  readBinaryFile();

  return 0;
}

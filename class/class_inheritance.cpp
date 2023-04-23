#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Human {
public:
  Human() { this->meta = "default meta"; }

  Human(string meta) { this->meta = meta; }

  string name;

  void SetName(string value) { this->name = std::move(value); };

  string GetName() { return this->name; }

  void PrintMeta() { cout << this->meta << endl; }

protected:
  void Say(const string &value) {
    cout << this->name << " says: " << value << endl;
  }

private:
  string meta;
};

class Student : public Human {
public:
  string group;
};

class Professor : public Human {
public:
  Professor() : Human("Professor") {}

  string subject;
};

class Car {
public:
  void Describe() { cout << "This is part of car" << endl; }

  void Drive() { cout << "Driving" << endl; }
};

class Airplane {
public:
  void Describe() { cout << "This is part of airplane" << endl; }

  void Fly() { cout << "Flying" << endl; }
};

class FlyingCar : public Car, public Airplane {};

int main() {
  //    Student student;
  //    Professor professor;
  //
  //    student.SetName("Harry");
  //    professor.SetName("Hagrid");
  //
  //    professor.PrintMeta();

  FlyingCar flyingCar;

  flyingCar.Drive();
  flyingCar.Car::Describe();
}
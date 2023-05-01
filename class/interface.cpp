#include <iostream>
#include <string>

using namespace std;

class IBicycle {
  public:
    virtual void Turn() = 0;

    virtual void Ride() = 0;
};

class Bicycle : public IBicycle {
    void Turn() override {
      cout << "Turn" << endl;
    }

    void Ride() override {
      cout << "Ride" << endl;
    }
};

class SportBicycle : public IBicycle {
    void Turn() override {
      cout << "SportBicycle Turn" << endl;
    }

    void Ride() override {
      cout << "SportBicycle Ride" << endl;
    }
};

class Human {
  public:
    void RideOn(IBicycle &bicycle) {
      bicycle.Ride();

      bicycle.Turn();
    }
};

int main() {
  Human human;
  Bicycle bicycle;
  SportBicycle sportBicycle;

  human.RideOn(sportBicycle);
}
#include <iostream>
#include <string>

using namespace std;

class Weapon {
public:
    virtual void Use() = 0;

    void Destroy() {
        cout << "Destroyed weapon" << endl;
    }

    virtual ~Weapon() {
        cout << "Weapon Destructor" << endl;
    }
};

class Gun : public Weapon {
public:
    void Use() override {
        cout << "Pof" << endl;
    }

    ~Gun() override {
        cout << "Gun Destructor" << endl;
    }
};

class SubmachineGun : public Weapon {
public:
    void Use() override {
        cout << "Pof Pof Pof" << endl;
    }

    ~SubmachineGun() override {
        cout << "SubmachineGun Destructor" << endl;
    }
};

class Knife : public Weapon {
public:
    void Use() override {
        cout << "Swing" << endl;
    }

    ~Knife() override {
        cout << "Knife Destructor" << endl;
    }
};

class Player {
public:
    void Fire(Weapon* weapon) {
        weapon->Use();
    }
};

int main() {
    Weapon* weapon = new Gun;

    delete weapon;
}
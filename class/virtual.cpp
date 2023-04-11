#include <iostream>
#include <string>

using namespace std;

class Gun {
public:
    virtual void Fire() {
        cout << "Pof" << endl;
    }
};

class SubmachineGun : public Gun {
public:
    void Fire() override {
        cout << "Pof Pof Pof" << endl;
    }
};

class Player {
public:
    void Fire(Gun* gun) {
        gun->Fire();
    }
};

int main() {
    Gun handgun;
    SubmachineGun submachineGun;

    Gun* weapon = &submachineGun;

    Player player;
    player.Fire(weapon);
}
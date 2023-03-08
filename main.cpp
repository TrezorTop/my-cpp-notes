#include <iostream>
#include <string>

using namespace std;


class Human {
private:
    string name;
    int age;
    int weight;

    int *livedAges;

public:
    Human() {
//        cout << "Constructor " << this << endl;

        this->name = "Unknown";
        this->age = 0;
        this->weight = 0;
    }

    Human(string name, int age, int weight) {
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->livedAges = new int[age];

        for (int i = 0; i < age; i++) {
            livedAges[i] = i;
        }
    }

    string GetName() {
        return this->name;
    }

    void SetName(string name) {
        this->name = name;
    }

    int GetAge() {
        return this->age;
    }

    void SetAge(int age) {
        this->age = age;
    }

    int GetWeight() {
        return this->weight;
    };

    void SetWeight(int weight) {
        this->weight = weight;
    }

    void Describe() {
        cout << "Human" << endl;
        cout << "name" << '\t' << this->name << endl;
        cout << "age" << '\t' << this->age << endl;
        cout << "weight" << '\t' << this->weight << endl;
    }

    Human(const Human &other) {
//        cout << "Copy Constructor " << this << endl;

        this->name = other.name;
        this->age = other.age;
        this->weight = other.weight;
        this->livedAges = new int[other.age];
        for (int i = 0; i < other.age; i++) {
            this->livedAges[i] = i;
        }
    }

    Human &operator=(const Human &other) {
//        cout << "Operator '=' " << this << endl;

        delete[] this->livedAges;

        this->name = other.name;
        this->age = other.age;
        this->weight = other.weight;
        this->livedAges = new int[other.age];
        for (int i = 0; i < other.age; i++) {
            this->livedAges[i] = i;
        }

        return *this;
    }

    bool operator==(const Human &other) {
        if (this->name != other.name || this->age != other.age || this->weight != other.weight)
            return false;

        for (int i = 0; i < age; ++i) {
            if (this->livedAges[i] != other.livedAges[i]) return false;
        }

        return true;
    }

    bool operator!=(const Human &other) {
        if (this->name != other.name || this->age != other.age || this->weight != other.weight)
            return true;

        for (int i = 0; i < age; ++i) {
            if (this->livedAges[i] != other.livedAges[i]) return true;
        }

        return false;
    }

    ~Human() {
//        cout << "Destructor " << this << endl;

        delete[] livedAges;
    }
};


void editHuman(Human &human) {
    human.SetName("Andrey");
}

int main() {
    Human human("andrey", 5, 15);

    Human secondHuman("andrey", 3, 15);

    editHuman(human);
}

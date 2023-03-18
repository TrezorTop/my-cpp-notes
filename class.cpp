#include <iostream>
#include <string>

using namespace std;

class Apple;

class Human {
private:
    string name;
    int age;
    int weight;

    int* livedAges;

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

    static void TakeApple(Apple& apple);

    static void EatApple(Apple& apple);

    Human(const Human& other) {
//        cout << "Copy Constructor " << this << endl;

        this->name = other.name;
        this->age = other.age;
        this->weight = other.weight;
        this->livedAges = new int[other.age];
        for (int i = 0; i < other.age; i++) {
            this->livedAges[i] = i;
        }
    }

    Human& operator =(const Human& other) {
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

    bool operator ==(const Human& other) {
        if (this->name != other.name || this->age != other.age || this->weight != other.weight)
            return false;

        for (int i = 0; i < age; ++i) {
            if (this->livedAges[i] != other.livedAges[i]) return false;
        }

        return true;
    }

    Human operator +(const Human& other) {
        Human human("child", 0, 0);
        return human;
    }

    Human& operator ++() {
        ++this->age;

        delete[] livedAges;
        this->livedAges = new int[age];
        for (int i = 0; i < age; ++i) {
            this->livedAges[i] = i;
        }

        return *this;
    }

    Human operator ++(int) {
        Human temp(*this);

        this->age++;

        delete[] livedAges;
        this->livedAges = new int[age];
        for (int i = 0; i < age; ++i) {
            this->livedAges[i] = i;
        }

        return temp;
    }

    Human& operator --() {
        --this->age;

        delete[] livedAges;
        this->livedAges = new int[age >= 0 ? age : 0];
        for (int i = 0; i < age; ++i) {
            this->livedAges[i] = i;
        }

        return *this;
    }

    Human operator --(int) {
        Human temp(*this);

        this->age--;

        delete[] livedAges;
        this->livedAges = new int[age >= 0 ? age : 0];
        for (int i = 0; i < age; ++i) {
            this->livedAges[i] = i;
        }

        return temp;
    }

    int& operator [](int index) {
        return this->livedAges[index];
    }

    bool operator !=(const Human& other) {
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

class Apple {
    static string* idsPool;
    friend Human;

private:
    int weight;
    string color;

public:
    int id;
    static int count;

    Apple(int weight, string color) {


        this->weight = weight;
        this->color = color;

        Apple::count++;

        this->id = Apple::count;
    }
};

int Apple::count;

void editHuman(Human& human) {
    human.SetName("Andrey");
}

void Human::TakeApple(Apple& apple) {
    if (Apple::count > 0)
        cout << "Took an " << apple.color << " apple (weight: " << apple.weight << ", total count: " << Apple::count
             << ')'
             << endl;
    else cout << "No more apples" << endl;
}

void Human::EatApple(Apple& apple) {
    if (Apple::count > 0) {
        --Apple::count;
        cout << "Ate an " << apple.color << " apple (weight: " << apple.weight << ", total count: " << Apple::count
             << ')'
             << endl;
    } else cout << "No more apples left" << endl;

}

int main() {
    Human human("andrey", 5, 15);

    Apple greenApple(221, "green");
    Apple redApple(121, "red");

    cout << greenApple.id << ' ' << redApple.id << endl;
}

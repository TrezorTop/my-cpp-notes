#include <iostream>
#include <string>

using std::cout, std::string;

template<typename T>
class SmartPointer {
public:
    SmartPointer(T* ptr) {
        this->ptr = ptr;
        refCount = new int(1);
    }

    SmartPointer(const SmartPointer<T>& other) {
        this->ptr = other.ptr;
        this->refCount = other.refCount;
        (*this->refCount)++;
    }

    ~SmartPointer() {
        (*this->refCount)--;

        if (*this->refCount == 0) {
            delete this->ptr;
        }
    }

    T& operator *() {
        return *this->ptr;
    }

    friend std::ostream& operator << <>(std::ostream& os, const SmartPointer& ptr);

private:
    T* ptr;
    int* refCount;
};

template<typename T>
std::ostream& operator <<(std::ostream& os, const SmartPointer<T>& ptr) {
    os << &ptr.ptr;
    return os;
}

int main() {
    SmartPointer ptr = new double(5);

    SmartPointer ptr2 = ptr;

    return 0;
}

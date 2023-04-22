#include <iostream>
#include <string>
#include <exception>

using namespace std;

void tryCatch() {
    try {
        // Some code that might throw an exception
        string s = "hello";
        char c = s.at(10); // This will throw an out_of_range exception
        cout << c << endl; // This will not be executed
    } catch (const exception& exception) {
        // Handle the exception
        cout << exception.what() << endl;
    }
}

void positiveInteger(int value) {
    if (value < 0) {
        throw runtime_error("Given value is not positive integer");
    }

    cout << value << endl;
}

void throwException() {
    try {
        positiveInteger(-10);
    } catch (const runtime_error& exception) {
        cout << "what(): " << exception.what() << endl;
    } catch (const char* exception) { // This will be executed when string thrown
        cout << "char* exception: " << exception << endl;
    } catch (...) {
        cout << "any exception" << endl;
    }
}

int main() {
//    tryCatch();
    throwException();


    return 0;
}

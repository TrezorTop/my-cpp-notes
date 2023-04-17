#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;

int main() {
    ofstream outFile;

    string filePath = filesystem::current_path().parent_path().string() + "/file/";
    string fileName = "example.txt";

    outFile.open(filePath + fileName, ofstream::app);

    if (!outFile.is_open()) {
        cout << "Could not open file" << endl;
        return 1;
    }

    outFile << "Hello, world!" << endl;

    string input;
    getline(cin, input);

    outFile << input << endl;

    outFile.close();

    return 0;
}
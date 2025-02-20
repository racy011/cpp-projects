#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream file("data.txt");
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string line;
    int lineCount = 0;
    int wordCount = 0;

    while(getline(file, line)) {
        lineCount++;
        istringstream iss(line);
        string word;
        while(iss >> word) {
            wordCount++;
        }
    }

    file.close();

    cout << "File Analysis:" << endl;
    cout << "Total Lines: " << lineCount << endl;
    cout << "Total Words: " << wordCount << endl;

    return 0;
}

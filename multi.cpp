#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool checkMultiLineComment(const string& code) {
    const char* start = strstr(code.c_str(), "/*");
    const char* end = strstr(code.c_str(), "*/");

    // Check if "/*" exists but "*/" does not
    if (start != nullptr && end == nullptr) {
        return true; // Unterminated comment
    }
    return false;
}

int main() {
    string code;

    cout << "Enter C program code: ";
    getline(cin, code); // Read the entire code as input

    if (checkMultiLineComment(code)) {
        cout << "Error: Unterminated multi-line comment." << endl;
    } else {
        cout << "No unterminated comments." << endl;
    }

    return 0;
}

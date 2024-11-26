#include <iostream>
#include <string>

using namespace std;

bool isValidIf(const string& code) {
    // Check for the presence of required substrings using `find`
    bool hasIf = code.find("if") >= 0;
    bool hasElse = code.find("else") >= 0;
    bool hasOpenParenthesis = code.find("(") >= 0;
    bool hasCloseParenthesis = code.find(")") >= 0;
    bool hasOpenBrace = code.find("{") >= 0;
    bool hasCloseBrace = code.find("}") >= 0;

    return hasIf && hasElse && hasOpenParenthesis && hasCloseParenthesis && hasOpenBrace && hasCloseBrace;
}

int main() {
    string code;

    cout << "Enter the if statement: ";
    getline(cin, code); // Read the entire line of input

    if (isValidIf(code)) {
        cout << "The if statement is valid." << endl;
    } else {
        cout << "Invalid if statement." << endl;
    }

    return 0;
}

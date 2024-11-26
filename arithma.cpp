#include <iostream>
#include <string>

using namespace std;

class ArithmeticRecognizer {
public:
    static bool isArithmeticExpression(const string& exp) {
        for (char c : exp) {
            if (isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/') {
                return true;
            }
        }
        return false;
    }
};

int main() {
    string exp;

    cout << "Enter an expression: ";
    cin >> exp; // Read a single input (no spaces)

    if (ArithmeticRecognizer::isArithmeticExpression(exp)) {
        cout << "This is an arithmetic expression." << endl;
    } else {
        cout << "This is not an arithmetic expression." << endl;
    }

    return 0;
}

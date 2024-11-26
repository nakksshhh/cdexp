#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class DeclarativeRecognizer {
public:
    static bool isDeclarative(const string& statement) {
        istringstream iss(statement);
        string firstWord;
        iss >> firstWord; // Get the first word of the statement
        return (firstWord == "int" || firstWord == "float" || firstWord == "char");
    }
};

int main() {
    string statement;

    cout << "Enter a statement: ";
    getline(cin, statement); // Read the whole line as input

    if (DeclarativeRecognizer::isDeclarative(statement)) {
        cout << "This is a declarative statement." << endl;
    } else {
        cout << "This is not a declarative statement." << endl;
    }

    return 0;
}

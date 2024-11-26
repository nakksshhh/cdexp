#include <bits/stdc++.h>
using namespace std;

enum Type {
    INVALID,
    INT,
    FLOAT,
    STRING,
    BOOL
};

// Function to convert string to Type enum
Type stringToType(const string &typeStr) {
    if (typeStr == "int") return INT;
    if (typeStr == "float") return FLOAT;
    if (typeStr == "string") return STRING;
    if (typeStr == "bool") return BOOL;
    return INVALID;
}

// Function to convert Type enum to string (for error reporting)
string typeToString(Type type) {
    switch (type) {
        case INT: return "int";
        case FLOAT: return "float";
        case STRING: return "string";
        case BOOL: return "bool";
        default: return "INVALID";
    }
}

class Symbol {
public:
    string name;
    Type type;

    Symbol() : name(""), type(INVALID) {}
    Symbol(string name, Type type) : name(name), type(type) {}
};

// Global symbol table
unordered_map<string, Symbol> symbolTable;

// Function to declare a variable in the symbol table
void declareVariable(const string &name, const string &typeStr) {
    Type type = stringToType(typeStr);
    if (type == INVALID) {
        throw invalid_argument("Invalid type: " + typeStr);
    }
    symbolTable[name] = Symbol(name, type);
}

// Function to check if a variable's type matches the expected type
void checkVariableType(const string &name, const string &typeStr) {
    if (symbolTable.find(name) == symbolTable.end()) {
        throw invalid_argument("Variable " + name + " not declared");
    }

    Type expectedType = stringToType(typeStr);
    if (expectedType == INVALID) {
        throw invalid_argument("Invalid type: " + typeStr);
    }

    Type actualType = symbolTable[name].type;
    if (expectedType != actualType) {
        throw invalid_argument("Type mismatch: " + name + " expected " + typeStr +
                                " but found " + typeToString(actualType));
    }
    cout << "Variable " << name << " is of type " << typeStr << endl;
}

int main() {
    try {
        // Declare some variables
        declareVariable("a", "int");
        declareVariable("b", "float");
        declareVariable("str", "string");

        // Check variable types
        checkVariableType("a", "int");     // Correct
        checkVariableType("b", "float");   // Correct
        checkVariableType("str", "string"); // Correct
        checkVariableType("a", "float");   // Type mismatch
    }
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

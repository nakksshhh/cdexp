#include <bits/stdc++.h>
using namespace std;

struct SymbolInfo {
    string type;
    string value;
    string scope;
};

void createSymbolTable(const vector<string>& lines) {
    unordered_map<string, SymbolInfo> symbolTable;
    regex varRegex(R"((int|float|double|char)\s+([a-zA-Z_][a-zA-Z0-9_]*)(\s*=\s*([^;]*))?)"); // Match type, name, and optional initialization
    regex funcRegex(R"((int|float|double|char)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*\()"); // Match function declarations

    string currentScope = "global"; // Assume global scope initially

    for (const string& line : lines) {
        smatch match;

        // Update current scope if a function declaration is found
        if (regex_search(line, match, funcRegex)) {
            string type = match[1];
            string name = match[2];
            currentScope = name; // Scope changes to the function name
            symbolTable[name] = {type, "N/A", "global"};
            continue;
        }

        // Match variable declarations
        if (regex_search(line, match, varRegex)) {
            string type = match[1];
            string name = match[2];
            string value = match[4].str(); // Capture initialization value, if any
            if (value.empty()) value = "N/A";
            symbolTable[name] = {type, value, currentScope};
        }
    }

    // Print the symbol table
    cout << "Symbol Table:\n";
    cout << "Name\t\tType\t\tValue\t\tScope\n";
    for (const auto& entry : symbolTable) {
        cout << entry.first << "\t\t" 
             << entry.second.type << "\t\t" 
             << entry.second.value << "\t\t" 
             << entry.second.scope << "\n";
    }
}

int main() {
    string fileName = "input.c";
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << fileName << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    createSymbolTable(lines);
    return 0;
}

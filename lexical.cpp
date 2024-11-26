#include <bits/stdc++.h>
using namespace std;

// Structure to store symbol information
struct Symbol {
    string name;
    string type;
};

// Function to check if a token is a keyword
bool isKeyword(const string& value) {
    static const vector<string> keywords = {
        "int", "float", "char", "if", "else", "for", "while", "return", "break", "continue", "void"
    };
    return find(keywords.begin(), keywords.end(), value) != keywords.end();
}

// Function to check if a token is an operator
bool isOperator(const string& value) {
    // Fix regex for operators: Move '-' to the start or end to avoid invalid range error
    return regex_match(value, regex("[+*/=<>!&|-]+"));
}

// Function to check if a token is a literal
bool isLiteral(const string& value) {
    return regex_match(value, regex("[0-9]+")) || regex_match(value, regex("\"[^\"]*\""));
}

// Function to check if a token is an identifier
bool isIdentifier(const string& value) {
    return regex_match(value, regex("[a-zA-Z_][a-zA-Z0-9_]*"));
}

// Function to display the symbol table
void displaySymbolTable(const map<string, Symbol>& symbolTable) {
    cout << "Symbol Table:\n";
    cout << "Name\t\tType\n";
    for (const auto& entry : symbolTable) {
        cout << entry.second.name << "\t\t" << entry.second.type << "\n";
    }
}

int main() {
    string filename = "inputlexi.txt";
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file " << filename << endl;
        return 1;
    }

    // Read the entire content of the file into a string
    string code((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    // Define a regex pattern to match tokens (variables, literals, operators, etc.)
    regex tokenRegex("[a-zA-Z_][a-zA-Z0-9_]*|[0-9]+|\"[^\"]*\"|[+*/=<>!&|-]+|;|,|\\(|\\)]");
    smatch match;
    map<string, Symbol> symbolTable;
    string::const_iterator searchStart(code.cbegin());

    // Tokenize and classify each token
    while (regex_search(searchStart, code.cend(), match, tokenRegex)) {
        string token = match.str();
        if (isKeyword(token)) {
            symbolTable[token] = {token, "Keyword"};
        } else if (isOperator(token)) {
            symbolTable[token] = {token, "Operator"};
        } else if (isLiteral(token)) {
            symbolTable[token] = {token, "Literal"};
        } else if (isIdentifier(token)) {
            symbolTable[token] = {token, "Identifier"};
        }
        // Move the search start to the end of the last match
        searchStart = match.suffix().first;
    }

    // Display the symbol table
    displaySymbolTable(symbolTable);

    return 0;
}

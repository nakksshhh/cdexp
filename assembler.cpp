#include <bits/stdc++.h>
void checkSymbols(const std::vector<std::string> &lines)
{
    std::unordered_set<std::string> definedSymbols;
    std::unordered_set<std::string> usedSymbols;
    std::unordered_map<std::string, int> lineNumbers;
    // Predefined symbols in assembly language
    std::unordered_set<std::string> predefinedSymbols = {
        "AX", "BX", "CX", "DX", "MOV", "ADD", "SUB", "JMP", "HLT"};
    // Parse through the lines and collect used and defined symbols
    for (int i = 0; i < lines.size(); ++i)
    {
        std::istringstream stream(lines[i]);
        std::string word;
        while (stream >> word)
        {
            // If the word ends with a colon, it is a label
            if (word.back() == ':')
            {
                std::string label = word.substr(0, word.length() - 1);
                definedSymbols.insert(label);
                lineNumbers[label] = i + 1;
            }
            // If the word is not predefined, consider it a used symbol
            else if (predefinedSymbols.find(word) == predefinedSymbols.end())
            {
                usedSymbols.insert(word);
                lineNumbers[word] = i + 1;
            }
        }
    }
    // Check for undefined symbols used in the code
    for (const auto &symbol : usedSymbols)
    {
        if (definedSymbols.find(symbol) == definedSymbols.end())
        {
            std::cout << "Error: Symbol '" << symbol << "' used at line "
                      << lineNumbers[symbol] << " but not defined.\n";
        }
    }
    // Check for symbols that are defined but not used
    for (const auto &symbol : definedSymbols)
    {
        if (usedSymbols.find(symbol) == usedSymbols.end())
        {
            std::cout << "Warning: Symbol '" << symbol << "' defined at line "
                      << lineNumbers[symbol] << " but not used.\n";
        }
    }
}
int main()
{
    std::string fileName = "sample.txt";
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return 1;
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }
    file.close();
    checkSymbols(lines);
    return 0;
}

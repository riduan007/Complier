#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Check keyword
bool isKeyword(string t) {
    return (t == "int" || t == "return" || t == "main" || t == "cout");
}

// Check number
bool isNumber(string t) {
    for (char c : t)
        if (!isdigit(c)) return false;
    return true;
}

int main() {

    ifstream file("lab_t.txt");
    string word = "";

    if (!file) {
        cout << "File not found!";
        return 0;
    }

    cout << "Token ---- Type\n\n";

    char c;
    while (file.get(c)) {

        // If space or punctuation or operator
        if (c == ' ' || c == '(' || c == ')' || c == '{' || c == '}' ||
            c == ';' || c == ',' || c == '=') {

            // Print previous collected word
            if (word != "") {
                if (isKeyword(word))
                    cout << word << " ---- keyword\n";
                else if (isNumber(word))
                    cout << word << " ---- number\n";
                else
                    cout << word << " ---- identifier\n";
                word = "";
            }

            // Print the symbol (except space)
            if (c != ' ') {
                if (c == '=')
                    cout << c << " ---- operator\n";
                else
                    cout << c << " ---- punctuation\n";
            }
        }
        else {
            word += c;  // build word
        }
    }

    // Print leftover last word
    if (word != "") {
        if (isKeyword(word))
            cout << word << " ---- keyword\n";
        else if (isNumber(word))
            cout << word << " ---- number\n";
        else
            cout << word << " ---- identifier\n";
    }

    return 0;
}


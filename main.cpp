#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isKeyword(string t) {
    return (t == "int" || t == "return" || t == "main" || t == "cout");
}

bool isNumber(string t) {
    for (char c : t)
        if (!isdigit(c)) return false;
    return true;
}

bool isPunctuation(char c) {
    return (c == '(' || c == ')' || c == '{' || c == '}' ||
            c == ';' || c == ',' );
}

bool isOperator(char c) {
    return (c == '=');
}

int main() {

    ifstream file("lab_t.txt");
    string line, token = "";

    if (!file) {
        cout << "File not found!";
        return 0;
    }

    cout << "Token   ----   Type\n\n";

    while (getline(file, line)) {

        for (int i = 0; i < line.size(); i++) {
            char c = line[i];

            // If punctuation or operator or space
            if (isPunctuation(c) || isOperator(c) || c == ' ') {

                // print previous token
                if (token != "") {

                    if (isKeyword(token))
                        cout << token << "  ----  keyword\n";
                    else if (isNumber(token))
                        cout << token << "  ----  number\n";
                    else
                        cout << token << "  ----  identifier\n";

                    token = "";
                }

                // print the punctuation/operator
                if (c != ' ') {
                    if (isPunctuation(c))
                        cout << c << "  ----  punctuation\n";
                    else if (isOperator(c))
                        cout << c << "  ----  operator\n";
                }
            }
            else {
                token += c;
            }
        }

        // leftover token
        if (token != "") {

            if (isKeyword(token))
                cout << token << "  ----  keyword\n";
            else if (isNumber(token))
                cout << token << "  ----  number\n";
            else
                cout << token << "  ----  identifier\n";

            token = "";
        }
    }

    return 0;
}

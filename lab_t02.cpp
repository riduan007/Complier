#include <iostream>
using namespace std;

int main() {
    string input;
    cout << "Enter an expression: ";
    cin >> input;

    cout << "Operators found: " << endl;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' ||
            input[i] == '/' || input[i] == '%' || input[i] == '=') {
            cout << "operator: " << input[i] << endl;
        }
    }

    return 0;
}


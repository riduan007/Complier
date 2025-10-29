
#include <iostream>
using namespace std;

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    if (!((word[0] >= 'A' && word[0] <= 'Z') ||
          (word[0] >= 'a' && word[0] <= 'z') ||
          (word[0] == '_'))) {
        cout << "Invalid Identifier";
        return 0;

    }

    for (int i = 1; i < word.length(); i++) {
        if (!((word[i] >= 'A' && word[i] <= 'Z') ||
              (word[i] >= 'a' && word[i] <= 'z') ||
              (word[i] >= '0' && word[i] <= '9') ||
              (word[i] == '_'))) {
            cout << "Invalid Identifier";
            return 0;

        }
    }

    cout << "Valid Identifier";
    return 0;
}

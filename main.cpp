#include <iostream>
#include <fstream>   // for reading file
using namespace std;

// Function to check if a word is a valid identifier
bool isIdentifier(string word) {
    // Check first character
    if (!((word[0] >= 'A' && word[0] <= 'Z') ||
          (word[0] >= 'a' && word[0] <= 'z') ||
          (word[0] == '_'))) {
        return false;
    }

    // Check the rest of the characters
    for (int i = 1; i < word.length(); i++) {
        if (!((word[i] >= 'A' && word[i] <= 'Z') ||
              (word[i] >= 'a' && word[i] <= 'z') ||
              (word[i] >= '0' && word[i] <= '9') ||
              (word[i] == '_'))) {
            return false;
        }
    }

    return true;
}

int main() {
    ifstream file("E:/new/AI/projectt/sample.txt");   // open the text file
    string word;

    if (!file.is_open()) {         // cSf file opened correctly
        cout << "File not found!" << endl;

    }else if (file.is_open()) {         // cSf file opened correctly
        cout << "File  found!" << endl;

    }

    // Read each word from the file
    while (getline(file,word)) {
        cout << word << " --> ";
        if (isIdentifier(word))
            cout << "Valid Identifier" << endl;
        else
            cout << "Invalid Identifier" << endl;
    }

    file.close(); // close the file after reading
    return 0;
}

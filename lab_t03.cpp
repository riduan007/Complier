
#include <iostream>
using namespace std;

int main() {
    char a, b;
    cout << "Enter first two characters: ";
    cin >> a >> b;

    if (a == '/' && b == '/')
        cout << "This is a single line comment.";
    else if (a == '/' && b == '*')
        cout << "This is a multiple line comment.";
    else
        cout << "This is not a comment line.";

    return 0;
}

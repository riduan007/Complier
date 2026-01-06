#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter string (a/b only): ";
    cin >> s;

    int state = 0;   // start state

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (state == 0)
        {
            if (c == 'b') state = 0;
            else if (c == 'a') state = 1;
            else state = -1;
        }
        else if (state == 1)
        {
            if (c == 'a') state = 1;
            else if (c == 'b') state = 2;
            else state = -1;
        }
        else if (state == 2)
        {
            if (c == 'a') state = 1;
            else state = -1;
        }
    }

    if (state == 1)
        cout << "ACCEPTED" << endl;
    else
        cout << "REJECTED" << endl;

    return 0;
}

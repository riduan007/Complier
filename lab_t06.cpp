#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements (max 100): ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Invalid number of elements!" << endl;
        return 1;
    }

    int arr[100];
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minimum = arr[0];
    int maximum = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minimum) minimum = arr[i];
        if (arr[i] > maximum) maximum = arr[i];
    }

    cout << "Minimum = " << minimum << endl;
    cout << "Maximum = " << maximum << endl;

    return 0;
}

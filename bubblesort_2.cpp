#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of temperatures: ";
    cin >> n;
    float temps[100];  
    cout << "Enter the temperatures: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> temps[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (temps[j] > temps[j + 1]) {
                // swap
                float temp = temps[j];
                temps[j] = temps[j + 1];
                temps[j + 1] = temp;
            }
        }
    }
    cout << "\nTemperatures in ascending order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << temps[i] << " ";
    }
    cout << endl;
    return 0;
}

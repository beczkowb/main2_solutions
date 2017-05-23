#include <iostream>

using namespace std;

int main() {
    int n, w;
    cin >> n;
    cin >> w;

    int A[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    int counter = 0;
    int current_sum = 0;
    for (int i = 0; i < n; i++) {
        current_sum += A[i];

        if (current_sum >= w) {
            counter++;
            current_sum = 0;
        }

    }

    cout << counter << endl;
}
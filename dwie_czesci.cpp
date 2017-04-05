#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int counter = 0;
    int candidate;
    for (int i = 0; i < n; i++) {
        if (counter == 0) {
            candidate = A[i];
            counter++;
        }
        else if (candidate == A[i]) {
            counter++;
        } else {
            counter--;
        }
    }

    counter = 0;
    for (int i = 0; i < n; i++)
        if (A[i] == candidate)
            counter++;

    if (counter <= n/2) {
        cout << 0 << endl;
        return 0;
    }

    int result = 0;
    int right = counter;
    for (int i = 0; i < n-1; i++) {
        if (A[i] == candidate)
            right--;

        if ((i+1)/2 < counter - right && (n-1-i)/2 < right)
            result++;
    }

    cout << result << endl;
}
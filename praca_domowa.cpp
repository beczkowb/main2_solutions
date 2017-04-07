#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    long long int current_val = 0;
    long long int left[n];
    left[0] = 0;
    long long int right[n];
    right[n-1] = 0;

    for (int i = 1; i < n; i++) {
        current_val += A[i];
        if (current_val < 0)
            current_val = 0;

        left[i] = current_val;
    }

    current_val = 0;

    for (int i = n-2; i >= 0; i--) {
        current_val += A[i];
        if (current_val < 0)
            current_val = 0;

        right[i] = current_val;
    }

    long long int result = 0;
    for (int i = 1; i < n-1; i++) {
        if (result < left[i-1] + right[i+1])
            result = left[i-1] + right[i+1];
    }

    cout << result << endl;
}
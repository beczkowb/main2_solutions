#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int diff_arr[n-1];
    for (int i = 1; i < n; i++)
        diff_arr[i-1] = -(A[i] - A[i-1]);

    int max_weight_loss = 0;
    int current_weight = 0;
    for (int i = 0; i < n-1; i++) {
        current_weight += diff_arr[i];
        if (current_weight < 0)
            current_weight = 0;

        if (current_weight > max_weight_loss)
            max_weight_loss = current_weight;
    }

    cout << max_weight_loss << endl;
}
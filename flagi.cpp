#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int number_of_peaks = 0;
    for (int i = 1; i < n-1; i++)
        if (A[i-1] < A[i] && A[i+1] < A[i])
            number_of_peaks++;

    int distances[number_of_peaks-1];
    int counter = 0;
    int counting_started = false;
    int d = 0;

    for (int i = 1; i < n && d < number_of_peaks-1; i++) {
        if (counting_started)
            counter++;

        if (A[i-1] < A[i] && A[i+1] < A[i]) {
            if (!counting_started)
                counting_started = true;
            else {
                distances[d++] = counter;
                counter = 0;
            }
        }
    }

    if (number_of_peaks == 0) {
        cout << 0 << endl;
        return 0;
    }

    int result = 0;
    int current_distance;

    for (int i = 2; i*i <= n; i++) {
        counter = 0;
        current_distance = 0;
        for (int j = 0; j < number_of_peaks-1; j++) {
            current_distance += distances[j];
            if (current_distance >= i) {
                counter++;
                current_distance = 0;
            }
            if (counter == i - 1) {
                result = i;
                break;
            }
        }
    }

    cout << result << endl;
}
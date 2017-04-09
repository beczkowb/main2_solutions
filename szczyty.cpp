#include <iostream>
#include <cmath>

using namespace std;

int count_flags(int divisor, int n, int peaks_counter[]) {
    int step = n / divisor;
    int flags_counter = 0;
    int start, end;

    for (int j = 0; j < divisor; j++) {
        start = j * step;
        end = start + step;
        if (peaks_counter[start] < peaks_counter[end])
            flags_counter++;
    }

    return flags_counter;
}

int main() {
    int n;
    cin >> n;

    if (n <= 2)
        cout << 0 << endl;

    int A[n];
    int peaks_counter[n+1];


    for (int i = 0; i < n; i++)
        cin >> A[i];

    peaks_counter[0] = 0;
    peaks_counter[1] = 0;
    for (int i = 2; i < n; i++) {
        peaks_counter[i] = peaks_counter[i-1];

        if (A[i-1] > A[i] && A[i-1] > A[i-2])
            peaks_counter[i]++;
    }


    peaks_counter[n] = peaks_counter[n-1];

    int current_division = 1;
    int flags_counter, flags_counter_symmetric;
    int max_flags = 0;

    while (current_division < sqrt(n)) {
        if (n % current_division == 0) {
            flags_counter = count_flags(current_division, n, peaks_counter);
            flags_counter_symmetric = count_flags(n/current_division, n, peaks_counter);

            if (flags_counter == current_division &&
                    flags_counter_symmetric != n/current_division &&
                    flags_counter > max_flags) {
                max_flags = flags_counter;
            }
            else if (flags_counter != current_division && flags_counter_symmetric == n/current_division && flags_counter_symmetric > max_flags) {
                max_flags = flags_counter_symmetric;
            } else if (flags_counter == current_division && flags_counter_symmetric == n/current_division && flags_counter_symmetric > max_flags) {
                max_flags = flags_counter_symmetric;
            }

        }
        current_division++;
    }

    if (current_division*current_division == n) {
        flags_counter = count_flags(current_division, n, peaks_counter);
        if (flags_counter == current_division && flags_counter > max_flags)
            max_flags = flags_counter;
    }

    cout << max_flags << endl;
}
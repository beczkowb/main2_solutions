#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int peaks_counter[n+1];
    peaks_counter[0] = 0;
    peaks_counter[1] = 0;
    int number_of_flags = 0;

    for (int i = 1; i < n-1; i++) {
        peaks_counter[i+1] = peaks_counter[i];
        if (A[i] > A[i-1] && A[i] > A[i+1]) {
            peaks_counter[i+1]++;
            number_of_flags++;
        }
    }
    peaks_counter[n] = peaks_counter[n-1];

    int flag_i = 0;
    int flags[number_of_flags];
    for (int i = 0; i < n; i++)
        if (A[i] > A[i-1] && A[i] > A[i+1])
            flags[flag_i++] = i;

    int max_number_of_flags = 0;
    int counter, flag, j;
    for (int k = 2; k <= sqrt(n); k++) {
        counter = 0;
        j = 0;
        while (j < number_of_flags) {
            counter++;
            flag = flags[j];

            if (peaks_counter[flag+k-1] < peaks_counter[n]) {
                j++;
                while (flag + k > flags[j]) {
                    j++;
                }
            } else {
                break;
            }

        }

        if (counter >= k) {
            max_number_of_flags = k;
        }
    }

    cout << max_number_of_flags << endl;

}
#include <iostream>

using namespace std;

int is_half_prime(int F[], int x) {
    int counter = 1;
    while (F[x] > 0 && counter < 2) {
        x /= F[x];
        counter++;
    }

    if (counter == 2 && F[x] == 0)
        return 1;
    else
        return 0;
}


int main() {
    int n;
    cin >> n;
    int intervals[2*n];

    for (int i = 0; i < 2*n; i++)
        cin >> intervals[i];

    int max = 0;
    for (int i = 0; i < 2*n; i++)
        if (max < intervals[i])
            max = intervals[i];

    int F[max+1];
    for (int i = 0; i < max+1; i++)
        F[i] = 0;

    for (int i=2; i * i < max+1; i++) {
        if (F[i] != 0)
            continue;

        for (int j=i*i; j < max+1; j += i)
            if (F[j] == 0)
                F[j] = i;
    }

    int half_primes[max+1];
    for (int i = 0; i < max+1; i++)
        half_primes[i] = is_half_prime(F, i);

    int prefix_sums_1[max+2];
    prefix_sums_1[0] = 0;
    int prefix_sums_2[max+2];
    prefix_sums_2[0] = 0;
    int prefix_sums_3[max+2];
    prefix_sums_3[0] = 0;

    int counter = 0;
    for (int i = 1; i < max+2; i++) {
        prefix_sums_1[i] = prefix_sums_1[i-1];
        prefix_sums_2[i] = prefix_sums_2[i-1];
        prefix_sums_3[i] = prefix_sums_3[i-1];
        //   0 0 1 0 1 1 1 0 1 1 0 0
        // 0 0 1 1 2 3 4 4
        if (half_primes[i-1] == 1)
            counter++;
        else
            counter = 0;

        if (counter == 1) {
            prefix_sums_1[i]++;
        } else if (counter == 2) {
            prefix_sums_1[i]++;
            prefix_sums_2[i]++;
        } else if (counter == 3) {
            prefix_sums_1[i]++;
            prefix_sums_2[i]++;
            prefix_sums_3[i]++;
        }
    }

    int a, b;

    for (int i = 0; i < n*2; i += 2) {
        a = intervals[i];
        b = intervals[i+1];

        if (prefix_sums_3[b+1] - prefix_sums_3[a] > 0) {
            if (prefix_sums_3[b+1] - prefix_sums_3[a] > 1) {
                cout << 3 << endl;
                continue;
            } else { // 1
                if(half_primes[a] == 1 && half_primes[a-1] == 1 && half_primes[a+1] == 1) {
                    cout << 2 << endl;
                    continue;
                } else if(half_primes[a] == 1 && half_primes[a+1] == 1 && half_primes[a+2] == 1) {
                    cout << 3 << endl;
                    continue;
                } else if (half_primes[a] == 1 && half_primes[a-1] == 1 && half_primes[a-2] == 1) {
                    // going to 2
                } else {
                    cout << 3 << endl;
                    continue;
                }
            }
        }

        if (prefix_sums_2[b+1] - prefix_sums_2[a] > 0) {
            if (prefix_sums_2[b+1] - prefix_sums_2[a] > 1) {
                cout << 2 << endl;
                continue;
            } else {
                if (half_primes[a] == 1 && half_primes[a+1]) {
                    cout << 2 << endl;
                    continue;
                } else if (half_primes[a] == 1 && half_primes[a-1]) {
                    cout << 1 << endl;
                    continue;
                } else {
                    cout << 2 << endl;
                    continue;
                }
            }
        }

        if (prefix_sums_1[b+1] - prefix_sums_1[a] > 0) {
            cout << 1 << endl;
            continue;
        }

        cout << 0 << endl;
    }

}
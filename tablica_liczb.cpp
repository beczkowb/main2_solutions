#include <iostream>


using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n];
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] > max) {
            max = A[i];
        }
    }
    int counter[max+1];
    for (int i = 0; i < max+1; i++)
        counter[i] = 0;

    for (int i = 0; i < n; i++)
        counter[A[i]]++;

    int sieve[max+1];
    for (int i = 0; i < max+1; i++)
        sieve[i] = 0;

    for (int i = 1; i < max+1; i++) {
        if (counter[i])
            for (int j = i; j < max+1; j += i) {
                sieve[j] += counter[i];
            }
    }

    for (int i = 0; i < n; i++)
        cout << n - sieve[A[i]] << " ";
}
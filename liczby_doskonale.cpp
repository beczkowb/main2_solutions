#include <iostream>
#include <cmath>

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

int is_perfect(int x, int F[]) {
    int original = x;
    int product = 1;
    while (F[x] > 0) {
        product *= F[x];
        x /= F[x];
        product *= x;
    }

    return product == original && x > 1;
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

    // half primes are potentially perfect
    int perfect_numbers[max+1];
    for (int i = 0; i < max+1; i++)
        perfect_numbers[i] = is_half_prime(F, i);

    // squares are not perfect
    for (int i = 2; i*i <= max+1; i++)
        perfect_numbers[i*i] = 0;

    // prime cubes are perfect
    for (int i = 2; i*i*i <= max+1; i++) {
        if (F[i] == 0)
            perfect_numbers[i*i*i] = 1;
    }

    int prefix_sums[max+2];
    prefix_sums[0] = 0;

    for (int i = 1; i < max+2; i++) {
        prefix_sums[i] = prefix_sums[i-1];
        prefix_sums[i] += perfect_numbers[i-1];
    }

    int a, b;
    for (int i = 0; i < 2*n; i += 2) {
        a = intervals[i];
        b = intervals[i+1];

        cout << prefix_sums[b+1] - prefix_sums[a] << endl;
    }
}
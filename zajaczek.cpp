#include <iostream>

using namespace std;

int min(int a, int b) {
    return a >= b ? b:a;
}

int main() {
    int n;
    cin >> n;

    int m[n+1];
    for (int i = 0; i < n+1; i++)
        cin >> m[i];

    int ile = 1;
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    while (fib[ile] < n) {
        ile++;
        fib[ile] = fib[ile-1] + fib[ile-2];
    }

    int skoki[n];

    for (int k = 0; k <= n; k++)
        skoki[k] = n + 1;

    if (m[0] == 0)
        skoki[0] = 0;

    for (int k = 1; k <= n; k++)
        if (m[k] == 0)
            for (int i = 1; i <= ile; i++)
                if (k - fib[i] >= 0)
                    skoki[k] = min(skoki[k], skoki[k - fib[i]] + 1);

    int wynik = -1;

    if (skoki[n] <= n)
        wynik = skoki[n];

    cout << wynik << endl;
}
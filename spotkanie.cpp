#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    unsigned long long int fib[60];
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < 60; i++)
        fib[i] = fib[i-1] + fib[i-2];

    cout << (fib[(n % 60)] + fib[(n % 60) - 2]) % 10 << endl;
}
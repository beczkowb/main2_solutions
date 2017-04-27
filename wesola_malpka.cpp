#include <iostream>

using namespace std;

long long int gcd(long long int a, long long int b) {
    long long int r = a % b;
    if (r == 0)
        return b;
    else
        return gcd(b, r);
}

int main() {
    int n;
    cin >> n;
    long long int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cin >> b;
        if (b > a)
            b = b % a;
        if (b == 0) {
            cout << 1 << endl;
        } else {
            cout << (a*b/gcd(a, b))/b << endl;
        }
    }
}
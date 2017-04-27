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
    long long int capacity;
    cin >> capacity;

    if (capacity == 1) {
        cout << 2 << endl;
        return 0;
    } else if (capacity == 2) {
        cout << 4 << endl;
        return 0;
    }

    long long int a = capacity;
    long long int b = capacity - 1;
    long long int g = gcd(a, b);

    cout << a*b/g + g << endl;
}
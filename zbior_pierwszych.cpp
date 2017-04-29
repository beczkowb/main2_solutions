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
    int a, b;
    int g;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cin >> b;

        if (a == 1) {
            cout << "TAK" << endl;
            continue;
        } else if (b == 1 && a == 1) {
            cout << "TAK" << endl;
            continue;
        } else if (b == 1 && a != 1) {
            cout << "NIE" << endl;
            continue;
        }

        while (true) {
            if (a > b)
                g = (int)gcd(a, b);
            else
                g = (int)gcd(b, a);

            if (g == 1) {
                cout << "NIE" << endl;
                break;
            } else if (g == a) {
                cout << "TAK" << endl;
                break;
            } else {
                a /= g;
            }
        }
    }
}
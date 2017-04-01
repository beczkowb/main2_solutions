#include <iostream>

using namespace std;

int main() {
    int n;
    long long int result = 0;
    int east = 0;
    int s;

    cin >> n;

    for (int i=0; i < n; i++) {
        cin >> s;
        if (s == 0) {
            east++;
        } else {
            result += east;
        }
    }

    cout << result << endl;
}
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    int c[n];
    bool c_o[m+1];

    for (int i = 0; i < n; i++)
        cin >> c[i];

    for (int i = 0; i < m+1; i++)
        c_o[i] = false;

    long long counter = 0;
    long long left = 0;
    long long right = 0;

    while (right < n) {
        if (c_o[c[right]]) {
            counter += (1 + right-left)*(right-left)/2;
            while (c_o[c[right]])
                c_o[c[left++]] = false;
            counter -= (1 + right-left)*(right-left)/2;
        }
        c_o[c[right++]] = true;
    }

    right--;
    counter += ((1 + right-left+1)*(right-left+1))/2;

    cout << counter << endl;
}
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    int results[m];
    int ch[n];
    for (int i=0; i < n; i++)
        cin >> ch[i];

    int ch1[n+1], ch2[n+1], ch3[n+1], ch4[n+1], ch5[n+1];
    ch1[0] = ch2[0] = ch3[0] = ch4[0] = ch5[0] = 0;

    for (int i=1; i < n+1; i++) {
        ch1[i] = ch1[i-1];
        ch2[i] = ch2[i-1];
        ch3[i] = ch3[i-1];
        ch4[i] = ch4[i-1];
        ch5[i] = ch5[i-1];

        if (ch[i-1] == 1) {
            ch1[i] = ch1[i-1] + 1;
        } else if (ch[i-1] == 2) {
            ch2[i] = ch2[i-1] + 1;
        } else if (ch[i-1] == 3) {
            ch3[i] = ch3[i-1] + 1;
        } else if (ch[i-1] == 4) {
            ch4[i] = ch4[i-1] + 1;
        } else {
            ch5[i] = ch5[i-1] + 1;
        }
    }

    int a, b;
    for (int i=0; i < m; i++) {
        cin >> a;
        cin >> b;
        if (ch1[a-1] != ch1[b]) {
            results[i] = 1;
        } else if (ch2[a-1] != ch2[b]) {
            results[i] = 2;
        } else if (ch3[a-1] != ch3[b]) {
            results[i] = 3;
        } else if (ch4[a-1] != ch4[b]) {
            results[i] = 4;
        } else if (ch5[a-1] != ch5[b]) {
            results[i] = 5;
        }
    }

    for (int i=0; i < m; i++)
        cout << results[i] << endl;
}
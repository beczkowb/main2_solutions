#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int t[n];
    int w[n];
    for (int i = 0; i < n; i++)
        cin >> t[i];

    for (int i = 0; i < n; i++)
        cin >> w[i];

    long long sums[n+1+2*(n-1)];
    sums[n-1] = 0;
    for (int i = (n-1)+1; i < n+1+(n-1); i++)
        sums[i] = sums[i-1] + t[i-(n-1)-1];

    for (int i = 0; i < (n-1) + 1; i++)
        sums[i] = 0;

    for (int i = n+(n-1)+1; i < n+1+2*(n-1); i++)
        sums[i] = sums[i-1];

    int left, right, r, minimum;
    long long summary;
    minimum = -1;
    for (int i = 0; i < n; i++) {
        left = 0;
        right = n-1;
        minimum = -1;
        while (left <= right) {
            r = (left + right) / 2;
            summary = sums[(n-1) + 1 + i + r];
            summary -= sums[(n-1)+1+i-r-1];
            if (summary > w[i]) {
                right = r-1;
                minimum = r;
            } else if (summary < w[i]) {
                left = r+1;
            } else {
                minimum = r;
                break;
            }
        }

        cout << minimum << " ";
    }
}
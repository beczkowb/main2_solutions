#include <iostream>
#include <algorithm>

using namespace std;


long long not_less(long long x, long long a_sizes[], long long b_sizes[], long long len) {
    long long result = 0;
    long long j = len;
    for (long long i = 0; i <=  len; i++) {
        while (j >= 0 && (long long) a_sizes[i]*b_sizes[j] >= x)
            j--;
        result += len - j;
    }
    return result;
}


int main() {
    long long a, b, n, k;
    cin >> a;
    cin >> b;
    cin >> n;
    cin >> k;

    long long a_cuts[n+1];
    long long b_cuts[n+1];
    long long a_sizes[n+1];
    long long b_sizes[n+1];

    for (long long i = 0; i < n; i++)
        cin >> a_cuts[i];
    a_cuts[n] = a;

    for (long long i = 0; i < n; i++)
        cin >> b_cuts[i];

    b_cuts[n] = b;

    long long threshold = 0;
    for (long long i = 0; i < n+1; i++) {
        a_sizes[i] = a_cuts[i] - threshold;
        threshold = a_cuts[i];
    }

    threshold = 0;
    for (long long i = 0; i < n+1; i++) {
        b_sizes[i] = b_cuts[i] - threshold;
        threshold = b_cuts[i];
    }

    sort(a_sizes, a_sizes + n+1);
    sort(b_sizes, b_sizes + n+1);

    long long left, right, x, less_or_equal, greater_or_equal, final_result;
    long long result[2];
    left = 0;
    right = a*b;

    while(left <= right) {
        x = (left + right) / 2;

        if (not_less(x, a_sizes, b_sizes, n) >= k) {
            left = x + 1;
            final_result = x;
        } else {
            right = x - 1;
        }
    }

    cout << final_result << endl;
}
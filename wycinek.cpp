#include <iostream>

#include <sstream>

using namespace std;

void merge(long long A[][2], int start, int middle, int end) {
    int left_len = middle-start+1;
    int right_len = end-middle;

    long long left[left_len][2];
    long long right[right_len][2];

    for (int i=0; i < left_len; i++) {
        left[i][0] = A[start+i][0];
        left[i][1] = A[start+i][1];
    }

    for (int i=0; i < right_len; i++) {
        right[i][0] = A[middle+1+i][0];
        right[i][1] = A[middle+1+i][1];
    }

    int a = start;
    int l = 0;
    int r = 0;
    while (l < left_len && r < right_len) {
        if (left[l][0] < right[r][0]) {
            A[a][0] = left[l][0];
            A[a][1] = left[l][1];
            l++;
        } else if (left[l][0] > right[r][0]) {
            A[a][0] = right[r][0];
            A[a][1] = right[r][1];
            r++;
        } else {
            if (left[l][1] < right[r][1]) {
                A[a][0] = left[l][0];
                A[a][1] = left[l][1];
                l++;
            } else {
                A[a][0] = right[r][0];
                A[a][1] = right[r][1];
                r++;
            }
        }

        a++;
    }

    if (r < right_len) {
        while (r < right_len) {
            A[a][0] = right[r][0];
            A[a][1] = right[r][1];
            r++;
            a++;
        }
    } else {
        while (l < left_len) {
            A[a][0] = left[l][0];
            A[a][1] = left[l][1];
            l++;
            a++;
        }
    }
}

void sort_points(long long A[][2], int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;
        sort_points(A, start, middle);
        sort_points(A, middle+1, end);
        merge(A, start, middle, end);
    }
}

int main() {
    int n;
    long long s;
    cin >> n;
    cin >> s;

    int x[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];

    if (s < 0) {
        for (int i = 0; i < n; i++)
            x[i] = -x[i];
        s = -s;
    }

    long long sums[n+1];
    sums[0] = 0;

    for (int i = 1; i < n+1; i++)
        sums[i] = sums[i-1] + x[i-1];

    long long isums[n+1][2];
    for (int i = 0; i < n+1; i++) {
        isums[i][0] = sums[i];
        isums[i][1] = i;
    }

    sort_points(isums, 0, n+1);

    long long max_len = -1;
    int left = 0;
    int right = 0;

    while (right < n+1) {
        if (isums[right][0] - isums[left][0] > s) {
            left++;
        } else if (isums[right][0] - isums[left][0] < s) {
            right++;
        } else {
            if (isums[right][1] > isums[left][1])
                max_len = max(max_len, isums[right][1] - isums[left][1]);

            right++;
        }
    }

    if (max_len != -1)
        cout << max_len << endl;
    else
        cout << "BRAK" << endl;
}
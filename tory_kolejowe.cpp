#include <iostream>

using namespace std;

void merge(int A[][2], int start, int middle, int end) {
    int left_len = middle-start+1;
    int right_len = end-middle;

    int left[left_len][2];
    int right[right_len][2];

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
        } else {
            A[a][0] = right[r][0];
            A[a][1] = right[r][1];
            r++;
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

void sort_points(int A[][2], int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;
        sort_points(A, start, middle);
        sort_points(A, middle+1, end);
        merge(A, start, middle, end);
    }
}

int main() {
    int n;
    int x, y;
    cin >> n;
    int points[n][2];

    for (int i=0; i < n; i++) {
        cin >> x;
        cin >> y;
        points[i][0] = x;
        points[i][1] = y;
    }

    sort_points(points, 0, n-1);

    int distance = points[1][0] - points[0][0] + points[1][1] + points[0][1];
    int current_min = distance;
    int best_candidate;

    if (distance - points[1][1] < points[1][1])
        best_candidate = 0;
    else
        best_candidate = 1;

    for (int i=2; i < n; i++) {
        distance = points[i][0] - points[best_candidate][0] + points[i][1] + points[best_candidate][1];
        if (current_min > distance)
            current_min = distance;

        if (distance - points[i][1] > points[i][1])
            best_candidate = i;
    }

    cout << current_min << endl;
}
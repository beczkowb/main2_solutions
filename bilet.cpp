#include <iostream>
#include <string>

using namespace std;

long int find_max_subarray(int A[], int n) {
    long int current_sum = 0;
    long int max = 0;
    for (int i = 0; i < n; i++) {
        current_sum += A[i];
        if (current_sum < 0)
            current_sum = 0;

        if (current_sum > max)
            max = current_sum;
    }

    return max;
}

long int find_min_subarray(int A[], int n) {
    for (int i = 0; i < n; i++)
        A[i] = -A[i];

    return -find_max_subarray(A, n);
}

long int maximize_profit(int A[], int n) {
    long int sum = 0;
    for (int i = 0; i < n; i++)
        sum += A[i];

    long int max_subarray = find_max_subarray(A, n);
    long int min_subarray = find_min_subarray(A, n);

    if (sum + max_subarray > sum - min_subarray)
        return sum + max_subarray;
    else
        return sum - min_subarray;

}

long int solution() {
    int n;
    cin >> n;
    n--;
    int A[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    return maximize_profit(A, n);
}

int main() {
    int z;
    cin >> z;

    for (int t = 0; t < z; t++) {
        cout << solution() << endl;
    }
}
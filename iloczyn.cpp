#include <iostream>
#include <algorithm>

using namespace std;

long long int max_product(int A[], int n) {
    sort(A, A+n);
    long long int negative_product = A[0] * A[1] * A[n-1];
    long long int positive_product = A[n-1] * A[n-2] * A[n-3];
    if (positive_product > negative_product)
        return positive_product;
    else
        return negative_product;
}

int main() {
    int z;
    int n;

    cin >> z;
    long long int results[z];

    for (int i=0; i < z; i++) {
        cin >> n;
        int A[n];
        for (int j=0; j < n; j++)
            cin >> A[j];

        results[i] = max_product(A, n);
    }

    for (int i=0; i < z; i++)
        cout << results[i] << endl;
}
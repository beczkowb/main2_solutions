#include <iostream>

using namespace std;

int main() {
    int n;
    int min_val;
    int A[n];
    int i;
    cin >> n;

    for (i=0; i < n; i++)
        cin >> A[i];

    min_val = A[0];
    for (i=1; i < n; i++)
        if (min_val > A[i])
            min_val = A[i];

    cout << min_val << ".00" << endl;
}

#include <iostream>

using namespace std;

unsigned long long pow(unsigned long long int x, int y) {
    unsigned long long result = x;
    for (int i = 1; i < y; i++)
        result *= x;

    return result;
}

int main() {
    int n;
    cin >> n;
    int pairs[2*n];
    int max = -1;
    int s, p;
    for (int i = 0; i < n; i++) {
        cin >> s;
        cin >> p;
        pairs[2*i] = s;
        pairs[2*i + 1] = p;
        if (max < s)
            max = s;
    }
    if (max < 2)
        max = 2;

    unsigned long long solution[max];

    solution[0] = 1;
    solution[1] = 2;
    for (int i = 2; i < max; i++) {
        solution[i] = solution[i-1] + solution[i-2];
    }

    for (int i = 0; i < n; i++)
        cout << solution[pairs[2*i]-1] % pow(2, pairs[2*i+1]) << endl;
}
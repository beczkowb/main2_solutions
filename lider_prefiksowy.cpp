#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;
    int A[n];
    int candidates[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    int candidate;
    int counter = 0;

    for (int i = 0; i < n; i++) {
        if (counter == 0) {
            candidate = A[i];
            counter++;
        } else if (candidate == A[i]) {
            counter++;
        } else {
            counter--;
        }

        if (counter == 0)
            candidates[i] = NULL;
        else
            candidates[i] = candidate;

    }

    int prefix_candidate;
    int prefix_counter = 0;

    for (int i = 0; i < n; i++) {
        if (candidates[i] != NULL && prefix_counter == 0) {
            prefix_candidate = candidates[i];
            prefix_counter++;
        } else if (candidates[i] != NULL && prefix_candidate == candidates[i]) {
            prefix_counter++;
        } else if (candidates[i] != NULL && prefix_candidate != candidates[i]){
            prefix_counter--;
        }
    }

    if (prefix_counter == 0)
        cout << "NIE" << endl;
    else {
        counter = 0;
        for (int i = 0; i < n; i++)
            if (candidates[i] == prefix_candidate)
                counter++;

        if (counter > n/2)
            cout << prefix_candidate << endl;
        else
            cout << "NIE" << endl;
    }

}
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int people[n];

    for (int i=0; i < n; i++)
        cin >> people[i];

    unsigned long long int cost = 0;
    int min_cost = people[n-1] + 1;


    for (int i = n-1; i >= 0; i--) {
        if (people[i] < min_cost)
            min_cost = people[i];
        cost += min_cost;
    }


    cout << cost << endl;
}
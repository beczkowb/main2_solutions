#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int area;
    cin >> area;

    int current = 1;
    long long int min = 2*area/current + 2*current;

    while (current <= sqrt(area)) {
        if (area % current == 0 && 2*area/current + 2*current < min) {
            min = 2*area/current + 2*current;
        }
        current++;
    }

    cout << min << endl;

}
#include <iostream>

using namespace std;

int main() {
    int num_of_planks, num_of_nails;
    cin >> num_of_planks;
    cin >> num_of_nails;

    int planks[2*num_of_planks];
    int nails[num_of_nails];

    int farest_point = -1;
    int a, b;
    for (int i = 0; i < num_of_planks; i++) {
        cin >> a;
        cin >> b;
        if (b > farest_point)
            farest_point = b;

        planks[2*i] = a;
        planks[2*i + 1] = b;
    }

    for (int i = 0; i < num_of_nails; i++)
        cin >> nails[i];

    int sums[farest_point+1];
    int left, right, mid;
    int current_num_of_nails;
    int min_number_of_nails = num_of_nails;
    int all_nailed;
    left = 1;
    right = num_of_nails;

    while (left <= right) {
        mid = (left + right) / 2; // number of nails
        for (int i = 0; i < farest_point+1; i++)
            sums[i] = 0;

        for (int i = 0; i < mid; i++)
            sums[nails[i]] = 1;

        current_num_of_nails = 0;
        for (int i = 1; i < farest_point+1; i++) {
            if (sums[i] == 1)
                current_num_of_nails++;

            sums[i] = current_num_of_nails;
        }

        all_nailed = true;
        for (int i = 0; i < num_of_planks; i++) {
            a = planks[2*i];
            b = planks[2*i+1];

            if (sums[b] - sums[a-1] == 0) {
                all_nailed = false;
                break;
            }
        }

        if (!all_nailed) {
            left = mid + 1;
        } else {
            right = mid - 1;
            min_number_of_nails = mid;
        }
    }

    cout << min_number_of_nails << endl;
}
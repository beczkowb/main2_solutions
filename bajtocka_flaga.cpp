#include <iostream>

using namespace std;

int get_next_value(int counter[], int n, int prohibited) {
    counter[prohibited] = -1;
    int max = 0;

    for (int i = 0; i < n; i++)
        if (counter[i] > counter[max])
            max = i;

    return max;
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int first_max = 0;
    int second_max = 0;

    int first_counter[n];
    int second_counter[n];

    for (int i = 0; i < n; i++) {
        first_counter[i] = 0;
        second_counter[i] = 0;
    }

    for (int i = 0; i < n; i++)
        if (i % 2 == 0)
            first_counter[A[i]-1]++;
        else
            second_counter[A[i]-1]++;

    for (int i = 0; i < n; i++) {
        if (first_counter[i] > first_counter[first_max])
            first_max = i;

        if (second_counter[i] > second_counter[second_max])
            second_max = i;
    }
    int result;

    int number_of_first_elements = n%2 == 0 ? n/2: n/2+1;
    int next_most_common_from_first_elements;
    int next_most_common_from_second_elements;

    if (first_max == second_max) {  // problem
        if (number_of_first_elements == first_counter[first_max] && n/2 == second_counter[second_max]) {
            result = number_of_first_elements > n/2 ? n/2:number_of_first_elements;
        } else if (number_of_first_elements == first_counter[first_max] && n/2 != second_counter[second_max]) {
            next_most_common_from_second_elements = get_next_value(second_counter, n, second_max);
            result = n/2 - second_counter[next_most_common_from_second_elements];
        } else if (number_of_first_elements != first_counter[first_max] && n/2 == second_counter[second_max]) {
            next_most_common_from_first_elements = get_next_value(first_counter, n, first_max);
            result = number_of_first_elements - first_counter[next_most_common_from_first_elements];
        } else {
            if (first_counter[first_max] > second_counter[second_max]) {
                next_most_common_from_second_elements = get_next_value(second_counter, n, second_max);
                result = n/2 - second_counter[next_most_common_from_second_elements] + number_of_first_elements - first_counter[first_max];
            } else {
                next_most_common_from_first_elements = get_next_value(first_counter, n, first_max);
                result = number_of_first_elements - first_counter[next_most_common_from_first_elements] + n/2 - second_counter[second_max];
            }
        }
    } else {
        result = number_of_first_elements - first_counter[first_max] + n/2 - second_counter[second_max];
    }

    cout << result << endl;

}
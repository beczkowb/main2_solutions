#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    int values[n];
    int directions[n];

    stack<int> values_stack;
    stack<int> directions_stack;

    for(int i=0; i < n; i++)
        cin >> values[i];

    for(int i=0; i < n; i++)
        cin >> directions[i];

    bool fight = false;
    bool add_to_stack = false;

    for (int i=0; i < n; i++) {
        if (values_stack.empty() || !(directions_stack.top() == 1 && directions[i] == 0)) {
            values_stack.push(values[i]);
            directions_stack.push(directions[i]);
        } else {
            add_to_stack = true;
            while (!values_stack.empty()) {
                fight = directions_stack.top() == 1 && directions[i] == 0;
                if (fight && values_stack.top() > values[i]) {
                    add_to_stack = false;
                    break;
                } else if (fight && values_stack.top() < values[i]) {
                    values_stack.pop();
                    directions_stack.pop();
                    add_to_stack = true;
                } else {
                    add_to_stack = true;
                    break;
                }
            }

            if (add_to_stack) {
                values_stack.push(values[i]);
                directions_stack.push(directions[i]);
            }
        }
    }

    cout << values_stack.size() << endl;
}
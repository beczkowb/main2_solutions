#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_correct(string input) {
    stack<char> s;
    for (char c: input) {
        if (s.empty()) {
            s.push(c);
        } else if (c == ')' && s.top() == '(') {
            s.pop();
        } else if (c == ']' && s.top() == '[') {
            s.pop();
        } else if (c == '}' && s.top() == '{') {
            s.pop();
        } else {
            s.push(c);
        }
    }

    return s.empty();
}

int main() {
    int n;
    string test_case;
    cin >> n;

    for (int i=0; i < n; i++) {
        cin >> test_case;
        cout << (is_correct(test_case) ? "TAK":"NIE") << endl;
    }
}
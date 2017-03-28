#include <iostream>

using namespace std;

int main() {
  int n;
  int tmp = 0;
  cin >> n;

  unsigned long int expected_sum = 0;

  for (int i = 0; i < n; i++) {
    expected_sum += i + 1;
  }

  unsigned long int A_sum = 0;

  for (int i = 0; i < n-1; i++) {
    cin >> tmp;
    A_sum += tmp;
  }

  cout << expected_sum - A_sum << endl;
}

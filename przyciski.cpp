#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int n, m;
  int current_level = 0;
  int current_max = 0;
  int button;

  cin >> n;
  cin >> m;

  int A[n];
  for (int i = 0; i < n; i++)
    A[i] = 0;

  for (int i = 0; i < m; i++) {
    cin >> button; 

    if (button == n + 1) {
      current_level = current_max; 
    } else {
      if (A[button-1] < current_level)
        A[button-1] = current_level;

      A[button-1] += 1;

      if (A[button-1] > current_max)
        current_max = A[button-1];
    }

  }

  for (int i = 0; i < n; i++) {
    if (A[i] < current_level) 
      A[i] = current_level;
  }

  for (int i = 0; i < n; i++) {
    cout << A[i];
    if (i+1 < n)
      cout << ' ';
  }
    

  cout << endl;
}

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int n, m;
  int counter;
  int leaf;
  int done = false;

  cin >> n;
  cin >> m;
  int A[n];
  counter = n;
  
  for (int i = 0; i < n; i++)
    A[i] = 0;

  for (int i = 0; i < m; i++) {
    cin >> leaf;
    if (A[leaf-1] == 0)
      counter--;

    if (counter == 0) {
      cout << i+1 << endl;
      done = true;
      break;
    }
        
    A[leaf-1] += 1;
  }

  if (done == false)
    cout << -1 << endl;
}

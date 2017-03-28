#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int n;
  int x;
  bool result = true;
  cin >> n;

  int A[n];
  for (int i = 0; i < n; i++)
    A[i] = 0;
  

  for (int i = 0; i < n; i++) {
    cin >> x; 
    if (x <= n)
      A[x-1] += 1;
  }

  for (int i = 0; i < n; i++)
    if (A[i] == 0)
      result = false;

  if (result == true) {
    cout << "TAK" << endl;
  } else {
    cout << "NIE" << endl;
  } 
}

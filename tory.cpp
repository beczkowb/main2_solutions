#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  int nails_left;
  int max_ever;
  int current_element;
  int counter;

  cin >> n;
  cin >> k;
  int A[n];

  for (int i=0; i < n; i++)
    cin >> A[i];
  
  sort(A, A+n); 
  current_element = A[0];
  counter = 1;
  max_ever = -1;
 
  for (int i=1; i < n; i++) {
    if (current_element == A[i]) {
      counter++;
    } else {
      if (n-i >= k) {
        nails_left = k;
      } else {
        nails_left = n-i;
      } 

      counter += nails_left;      
      if (counter > max_ever)
        max_ever = counter;
      
      current_element = A[i];
      counter = 1;
    }
  }
  if (counter > max_ever)
    max_ever = counter;
  
  cout << max_ever << endl;
}

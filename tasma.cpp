#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int n;
  long int A_sum;
  long int min_diff;
  long int left_sum;
  long int right_sum;
  long int tmp;

  cin >> n;

  int A[n];
  A_sum = 0;

  for (int i=0; i < n; i++) {
    cin >> A[i];
    A_sum += A[i];
  }

  left_sum = A[0];
  right_sum = A_sum - left_sum;
  min_diff = abs(left_sum - right_sum); 

  for (int i=1; i < n-1; i++) {
    left_sum += A[i];
    right_sum = A_sum - left_sum;
    tmp = abs(left_sum - right_sum); 

    if (tmp < min_diff) {
        min_diff = tmp;
    }
  } 

  cout << min_diff << endl;
}

#include <iostream>

using namespace std;

int count_jumps(int x, int y, int s) {
    if (x == y) {
        return 0;
    }
    return 1 + (y - x - 1) / s;
}

int main() {
  int x, y, s;

  cin >> x;
  cin >> y;
  cin >> s;
  cout << count_jumps(x, y, s) << endl;
}

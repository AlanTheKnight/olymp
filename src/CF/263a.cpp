#include <iostream>
using namespace std;

int main() {
  bool x;
  int ans;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> x;
      if (x) ans = abs(i - 2) + abs(j - 2);
    }
  }
  cout << ans << endl;
}
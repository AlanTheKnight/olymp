#include <iostream>
using namespace std;

int main() {
  int cols, n, x, ans = 1000000;
  cin >> cols >> n;
  int field[cols];
  for (int i = 0; i < cols; i++) field[i] = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    field[x - 1]++;
  }
  for (int i = 0; i < cols; i++) ans = min(ans, field[i]);
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int f(int x, int n) {
  if (x <= n / 2) return x;
  return -x + n + 1;
}

int get_loop_n(int x, int y, int n) {
  if (y >= x && y >= -x + n + 1 || y <= x && y <= -x + n + 1) return f(y, n);
  return f(x, n);
}

void solve() {
  int n, x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;

  cout << abs(get_loop_n(x1, y1, n) - get_loop_n(x2, y2, n)) << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) solve();
}

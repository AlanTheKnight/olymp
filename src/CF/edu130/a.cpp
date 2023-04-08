#include <iostream>
using namespace std;

void solve() {
  int n, m, sm = 0;
  cin >> n >> m;

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sm += a[i];
  }

  cout << max(0, sm - m) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}

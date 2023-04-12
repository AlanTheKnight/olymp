#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, d;
  cin >> n >> d;

  string x;
  cin >> x;

  for (int i = 0; i <= n; i++) {
    if (i == n || x[i] - '0' < d) {
      x.insert(x.begin() + i, '0' + d);
      break;
    }
  }

  cout << x << endl;
}

int main() {
  freopen64("out.txt", "w", stdout);
  
  int t;
  cin >> t;

  while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> g(n, vector<bool>(n));

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    from--;
    to--;
    g[from][to] = true;
  }

  for (auto row : g) {
    for (auto i : row) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}

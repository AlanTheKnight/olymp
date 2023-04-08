#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> visited;
vector<int> cur_component;

void dfs(int u) {
  visited[u] = true;
  cur_component.push_back(u);
  for (auto n : g[u]) {
    if (!visited[n]) dfs(n);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  g.resize(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  visited.assign(n, false);

  vector<vector<int>> ans;

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      cur_component.clear();

      dfs(i);

      sort(cur_component.begin(), cur_component.end());
      ans.push_back(cur_component);
    }
  }

  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << x.size() << endl;
    for (auto i : x) cout << i + 1 << ' ';
    cout << endl;
  }
}

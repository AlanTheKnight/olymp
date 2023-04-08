#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> mt;
vector<char> used;

bool try_kuhn(int v) {
  if (used[v]) return false;
  used[v] = true;
  for (size_t i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (mt[to] == -1 || try_kuhn(mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}

int main() {
  int _;
  cin >> n >> _;

  vector<set<int>> juices;

  for (int i = 0; i < n; i++) {
    int l, x;
    cin >> l;
    set<int> cur;
    for (int j = 0; j < l; j++) {
      cin >> x;
      cur.insert(x);
    }
    juices.push_back(cur);
  }

  g.resize(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      set<int> diff;
      set_difference(juices[i].begin(), juices[i].end(), juices[j].begin(),
                     juices[j].end(), inserter(diff, diff.begin()));
      if (diff.size() == 0) g[i].push_back(j);
    }
  }

  // for (int i = 0; i < n; i++)
  // {
  //     cout << i << ' ';
  //     for (auto x : g[i])
  //         cout << x << ' ';
  //     cout << endl;
  // }

  mt.assign(n, -1);
  for (int v = 0; v < n; ++v) {
    used.assign(n, false);
    try_kuhn(v);
  }

  for (int i = 0; i < n; ++i)
    if (mt[i] != -1) printf("%d %d\n", mt[i] + 1, i + 1);
}
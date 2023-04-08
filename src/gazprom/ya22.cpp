#include <bits/stdc++.h>
using namespace std;

struct bipartite_matching {
  int n_left, n_right, flow = 0;
  vector<vector<int>> g;
  vector<int> match_from_left, match_from_right;

  bipartite_matching(int _n_left, int _n_right)
      : n_left(_n_left),
        n_right(_n_right),
        g(_n_left),
        match_from_left(_n_left, -1),
        match_from_right(_n_right, -1),
        dist(_n_left) {}

  void add(int u, int v) { g[u].push_back(v); }

  vector<int> dist;

  void bfs() {
    queue<int> q;
    for (int u = 0; u < n_left; ++u) {
      if (!~match_from_left[u])
        q.push(u), dist[u] = 0;
      else
        dist[u] = -1;
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : g[u])
        if (~match_from_right[v] && !~dist[match_from_right[v]]) {
          dist[match_from_right[v]] = dist[u] + 1;
          q.push(match_from_right[v]);
        }
    }
  }

  bool dfs(int u) {
    for (auto v : g[u])
      if (!~match_from_right[v]) {
        match_from_left[u] = v, match_from_right[v] = u;
        return true;
      }
    for (auto v : g[u])
      if (dist[match_from_right[v]] == dist[u] + 1 &&
          dfs(match_from_right[v])) {
        match_from_left[u] = v, match_from_right[v] = u;
        return true;
      }
    return false;
  }

  int get_max_matching() {
    while (true) {
      bfs();
      int augment = 0;
      for (int u = 0; u < n_left; ++u)
        if (!~match_from_left[u]) augment += dfs(u);
      if (!augment) break;
      flow += augment;
    }
    return flow;
  }

  pair<vector<int>, vector<int>> minimum_vertex_cover() {
    vector<int> L, R;
    for (int u = 0; u < n_left; ++u) {
      if (!~dist[u])
        L.push_back(u);
      else if (~match_from_left[u])
        R.push_back(match_from_left[u]);
    }
    return {L, R};
  }

  vector<pair<int, int>> get_edges() {
    vector<pair<int, int>> ans;
    for (int u = 0; u < n_left; ++u)
      if (match_from_left[u] != -1) ans.emplace_back(u, match_from_left[u]);
    return ans;
  }
};

int main() {
  int n, k;
  cin >> n >> k;

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

  bipartite_matching matching(n, n);

  vector<bool> ok(n, true);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      set<int> diff;
      set_difference(juices[i].begin(), juices[i].end(), juices[j].begin(),
                     juices[j].end(), inserter(diff, diff.begin()));
      if (diff.size() == 0) {
        // cout << i << " -> " << j << endl;
        matching.add(i, j);
        ok[j] = false;
      }
    }
  }

  cout << matching.get_max_matching() << '\n';
}

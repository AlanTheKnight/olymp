#include <bits/stdc++.h>
#define ll long long
#define INF 1000000007

using namespace std;

ll n, s, ans = -1;
vector<ll> used;
vector<vector<ll>> g;

void dfs(ll v, ll nv, ll ov) {
  if (ans != -1)
    ans = (s - (nv + ov) < 0) ? 0 : (ans * (s - (nv + ov))) % INF;
  else
    ans = (s - (nv + ov) < 0) ? 0 : (s - (nv + ov)) % INF;

  used[v] = true;
  ov = 0;
  nv = 1;

  for (auto &i : g[v])
    if (used[i]) ov++;

  for (auto &i : g[v]) {
    if (!used[i]) {
      dfs(i, ov, nv);
      ov++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> s;

  used.resize(n, false);
  g.resize(n);

  for (ll i = 0; i < n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  if (n == 1) {
    cout << s % INF << endl;
    return 0;
  }

  dfs(0, 0, 0);
  cout << ans << endl;
}
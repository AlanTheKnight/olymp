#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

int main() {
  ll n, k;
  cin >> n >> k;

  vector<vector<ll>> s(n);
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    s[i] = {a, b + 1};
  }

  sort(s.begin(), s.end(),
       [](vector<ll> v1, vector<ll> v2) { return v1[1] < v2[1]; });

  ll mxs = 0, l_i = 0, r_i = 0, curr = s[0][0];

  while (l_i != n) {
    if ((r_i + 1 < n) && (s[r_i + 1][1] - s[l_i][1] <= k * 2)) {
      r_i++;
      curr += s[r_i][0];
      mxs = max(mxs, curr);
    } else {
      l_i++;
      curr -= s[l_i - 1][0];
    }
  }

  cout << mxs << endl;
}

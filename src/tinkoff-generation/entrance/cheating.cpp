#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<ll>> a;
  ll n, k, x;
  cin >> n >> k;

  for (ll i = 0; i < n; i++) {
    cin >> x;
    a.push_back({x, i, -1});
  }

  vector<ll> copies_left(n, 2);

  sort(a.begin(), a.end(),
       [](vector<ll> v1, vector<ll> v2) { return v1[0] > v2[0]; });

  ll start = 0;
  for (ll i = 0; i < n; i++) {
    bool matched = false;

    if (i == 0) {
      a[i][2] = 0;
      continue;
    }

    for (ll l = start; l < i; l++) {
      // If solution can be copied
      if (a[l][0] - a[i][0] >= k && copies_left[l]) {
        copies_left[l]--;
        a[i][2] = a[l][1] + 1;
        matched = true;
        if (copies_left[l] != 0) start = l;
        break;
      }
    }

    if (!matched) {
      cout << -1 << endl;
      exit(0);
    }
  }

  sort(a.begin(), a.end(),
       [](vector<ll> v1, vector<ll> v2) { return v1[1] < v2[1]; });
  for (auto& i : a) cout << i[2] << " ";
  cout << endl;
}
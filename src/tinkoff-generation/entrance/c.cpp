#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, q, l, r, t;
  cin >> n;
  vector<ll> a;
  map<string, ll> m;
  for (int i = 0; i < n; i++) {
    cin >> t;
    a.push_back(t);
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> l >> r;
    string id = to_string(l) + to_string(r);
    if (m.find(id) != m.end())
      cout << m[id] << endl;
    else {
      set<ll> s;
      for (int j = l; j <= r; j++) s.insert(a[j - 1]);
      m[id] = (s.size() > 1) || !(s.count(1)) ? 1 : 2;
      cout << m[id] << endl;
    }
  }
}
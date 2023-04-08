#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define vi vector<int>
using namespace std;

ll dec(vi a, ll start) {
  a.erase(a.begin(), a.begin() + start - 1);
  reverse(a.begin(), a.end());
  ll res = 1, prev = a[0];
  for (ll i = 1; i < a.size(); i++) {
    if (i > prev) return res;
    res++;
    prev = i;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;

  vi a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];

  for (ll i = 0; i < n; i++) {
    if (a[i] == 1) {
      ll ans = dec(a, i);
      cout << (n - ans) << endl;
    }
  }
}

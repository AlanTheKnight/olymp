#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, q;
  cin >> n >> q;

  vector<ll> a(n), s(n + 1);
  for (auto &x : a) cin >> x;
  sort(a.begin(), a.end());

  for (size_t i = 0; i < n; i++) s[i + 1] = s[i] + a[i];

  for (size_t i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    cout << s[n - x + y] - s[n - x] << endl;
  }
}
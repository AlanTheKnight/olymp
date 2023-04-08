#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ll n, q, l, r;
  cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];

  cin >> q;

  for (ll i = 0; i < q; i++) {
    cin >> l >> r;
    set<ll> ss(a.begin() + l - 1, a.begin() + r);
    cout << ((ss.find(1) != ss.end() && ss.size() == 1) ? 2 : 1) << '\n';
  }
  cout << endl;
}

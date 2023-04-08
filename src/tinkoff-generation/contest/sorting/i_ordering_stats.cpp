#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  partial_sort(a.begin(), a.begin() + k, a.end());
  cout << a[k - 1] << endl;
}

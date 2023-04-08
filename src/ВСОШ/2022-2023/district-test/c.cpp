#include <bits/stdc++.h>
using namespace std;

void nextCombination(int n, int k, vector<int> a) {
  int lastNotEqualOffset = k - 1;
  while (a[lastNotEqualOffset] == n - k + (lastNotEqualOffset + 1))
    lastNotEqualOffset--;

  if (lastNotEqualOffset < 0) {
    cout << -1 << endl;
    return;
  }

  a[lastNotEqualOffset]++;

  for (int i = lastNotEqualOffset + 1; i < k; i++)
    a[i] = a[lastNotEqualOffset] + (i - lastNotEqualOffset);

  for (auto x : a) cout << x << ' ';
  cout << endl;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(k);

  for (int i = 0; i < k; i++) cin >> a[i];

  nextCombination(n, k, a);
}

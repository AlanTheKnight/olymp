#include <bits/stdc++.h>
#define ll long long
#define pint pair<int, int>
using namespace std;

bool comp(pint a, pint b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second > b.second;
}

int main() {
  int n;
  cin >> n;
  vector<pint> a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end(), comp);
  for (int i = 0; i < n; i++) cout << a[i].first << ' ' << a[i].second << endl;
}

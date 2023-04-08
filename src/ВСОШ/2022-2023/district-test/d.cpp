#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);

  for (int i = 0; i < n; i++) cin >> a[i];

  int s = 0;

  while (a.size() != 2) {
    vector<pair<int, int>> to_delete;
    for (int i = 1; i < n - 1; i++)
      to_delete.push_back({a[i] * (a[i - 1] + a[i + 1]), i});

    sort(to_delete.rbegin(), to_delete.rend());

    for (auto x : to_delete) printf("%d: %d; ", x.second, x.first);
    cout << endl;
    for (auto x : a) cout << x << ' ';
    cout << endl;
    cout << "Deleting " << to_delete[0].second << endl; 
    cout << "-----------" << endl;

    a.erase(a.begin() + to_delete[0].second);
    
    s += to_delete[0].first;
  }

  cout << s << endl;
}

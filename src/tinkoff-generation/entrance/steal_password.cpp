#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  char c;
  vector<pair<char, char>> a;
  int l = 0, r = s.length() - 1;
  while (l <= r) {
    if (s[l] != s[r]) {
      a.push_back(make_pair(min(s[l], s[r]), max(s[l], s[r])));
      if (a.size() > 2) {
        cout << "NO" << endl;
        exit(0);
      };
    }

    if (l == r) c = s[l];
    l++;
    r--;
  }

//   cout << c << endl;

//   for (auto i : a) {
//     cout << i.first << ' ' << i.second << endl;
//   }

  if (a.size() == 2 && a[0].first == a[1].first && a[0].second == a[1].second)
    cout << "YES";
  else {
    for (int i = a.size() - 1; i >= 0; i--) {
      if (a[i].first == c || a[i].second == c) {
        a.erase(a.begin() + i);
        break;
      }
    }

    cout << (a.size() ? "NO" : "YES");
  }

  cout << endl;
}
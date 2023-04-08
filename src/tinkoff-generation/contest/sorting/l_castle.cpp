#include <bits/stdc++.h>
using namespace std;

vector<int> weights(26);

bool comp(const pair<char, int> a, const pair<char, int> b) {
  return weights[(a.first - 'a')] > weights[(b.first - 'a')];
}

int main() {
  // freopen("tests/l/input.txt", "r", stdin);
  // freopen("tests/l/output.txt", "w", stdout);

  string s;
  getline(cin, s);

  for (int i = 0; i < 26; ++i) cin >> weights[i];

  vector<pair<char, int>> ns(26, {' ', 0});

  for (int i = 0; i < s.length(); ++i) {
    ns[(int)(s[i] - 'a')].first = s[i];
    ns[(int)(s[i] - 'a')].second++;
  }

  sort(ns.begin(), ns.end(), comp);

  vector<char> start, middle, end;

  for (auto x : ns) {
    if (x.second == 1) {
      middle.push_back(x.first);
      continue;
    }

    for (int i = 0; i < (x.second / 2); i++) {
      start.push_back(x.first);
      end.push_back(x.first);
    }

    if (x.second % 2) middle.push_back(x.first);
  }

  reverse(end.begin(), end.end());

  for (auto x : start) cout << x;
  for (auto x : middle) cout << x;
  for (auto x : end) cout << x;
  cout << endl;
}

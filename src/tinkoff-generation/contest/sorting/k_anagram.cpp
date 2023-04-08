#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool ans(string &s1, string &s2) {
  if (s1.length() != s2.length()) return false;

  map<char, int> m1, m2;
  for (auto c : s1) m1[c]++;
  for (auto c : s2) m2[c]++;

  if (s1.size() != s2.size()) return false;

  for (auto &x : m1) {
    if (m2[x.first] != x.second) return false;
  }

  for (auto &x : m2) {
    if (m1[x.first] != x.second) return false;
  }

  return true;
}

int main() {
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);

  cout << (ans(s1, s2) ? "YES" : "NO") << endl;
}

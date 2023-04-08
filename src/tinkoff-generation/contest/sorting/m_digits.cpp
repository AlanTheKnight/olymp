#include <bits/stdc++.h>
using namespace std;

bool isSmaller(string &str1, string &str2) {
  int n1 = str1.length(), n2 = str2.length();
  if (n1 != n2) return n1 > n2;
  int i = 0, j = 0;
  while (str1[i] == 0 && i < n1 - 1) i++;
  while (str1[j] == 0 && j < n2 - 1) j++;

  for (i, j; i < n1 && j < n2; i++, j++)
    if (str1[i] < str2[j])
      return true;
    else if (str1[i] > str2[j])
      return false;
  return false;
}

bool comp(string &a, string &b) {
  string c = a + b, d = b + a;
  return !isSmaller(c, d);
}

int main() {
  // freopen("tests/m/input.txt", "r", stdin);
  // freopen("tests/m/output.txt", "w", stdout);

  vector<string> a;
  string s;
  while (cin >> s) a.push_back(s);

  sort(a.begin(), a.end(), comp);

  for (auto &x : a) cout << x;
}

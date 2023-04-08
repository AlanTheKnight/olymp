#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  vector<int> cnt(30000, 0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x + 10000]++;
  }

  for (int i = 0; i < cnt.size(); i++) {
    if (cnt[i]) {
      for (int j = 0; j < cnt[i]; j++) {
        cout << i - 10000 << ' ';
      }
    }
  }
  cout << endl;
}

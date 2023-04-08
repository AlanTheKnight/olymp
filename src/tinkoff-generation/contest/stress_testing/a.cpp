#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;

void solution(vector<int> &a, int k) {
  multiset<int> w;
  for (int i = 0; i < a.size(); i++) {
    w.insert(a[i]);
    if (i - k >= 0) w.erase(w.find(a[i - k]));
    if (i >= k - 1) cout << *w.begin() << ' ';
  }
  cout << endl;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  solution(a, k);

  return 0;
}

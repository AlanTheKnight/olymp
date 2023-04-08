#include <climits>
#include <iostream>
using namespace std;

const int INF = INT_MAX;

int find_min_index(int start, int* a, int n) {
  pair<int, int> res = {INF, -1};
  for (int i = start; i < n; i++) {
    if (a[i] < res.first) {
      res.first = a[i];
      res.second = i;
    }
  }
  return res.second;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < n; i++) {
    int min_ind = find_min_index(i, a, n);
    swap(a[i], a[min_ind]);
  }

  for (int i = 0; i < n; i++) cout << a[i] << ' ';
  cout << endl;
}

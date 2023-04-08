#include <bits/stdc++.h>
using namespace std;

long divisorCount(int n) {
  long res = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (i != (n / i))
        res += 2;
      else
        res++;
    }
  }
  return res;
}

int main() {
  int n;
  cin >> n;

  pair<int, int> mx = {-1, -1};
  for (int i = 1; i <= n; i++) {
    long r = divisorCount(i);
    if (r > mx.first) mx = {r, i};
  }

  cout << mx.second << endl;
  cout << mx.first << endl;
}

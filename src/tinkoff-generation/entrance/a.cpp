#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int fn = (3 * i) % 5 + 1;
    for (int j = 0; j < m; j++) cout << ((fn + j - 1) % 5 + 1) << ' ';
  }
  cout << endl;
}

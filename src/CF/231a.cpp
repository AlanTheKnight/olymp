#include <iostream>
using namespace std;

int main() {
  int n, cnt = 0, a, b, c;
  cin >> n;
  while (n--) {
    cin >> a >> b >> c;
    if (a + b + c >= 2) cnt++;
  }
  cout << cnt << endl;
}
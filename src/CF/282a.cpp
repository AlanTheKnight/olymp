#include <iostream>
using namespace std;

int main() {
  int n, x = 0;
  cin >> n;
  while (n--) {
    char c[3];
    cin >> c[0] >> c[1] >> c[2];
    if (c[1] == '-')
      x--;
    else
      x++;
  }
  cout << x << endl;
}
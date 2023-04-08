#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define ull unsigned long long

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  //   freopen("tests/c-input.txt", "r", stdin);

  //   freopen("tests/c-output.txt", "w", stdout);

  deque<int> d;

  int k;
  cin >> k;
  while (k--) {
    char action;
    int x;
    cin >> action;

    if (action == '+') {
      cin >> x;
      d.push_back(x);
    } else if (action == '*') {
      cin >> x;
      int ins_pos = d.size() / 2 + (d.size() % 2 == 0 ? -1 : 0) + 1;
      d.insert(d.begin() + ins_pos, x);
    } else {
      cout << d.front() << '\n';
      d.pop_front();
    }
  }

  return 0;
}

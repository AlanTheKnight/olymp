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

  // freopen("tests/b-output.txt", "w", stdout);
  // freopen("tests/b-input.txt", "r", stdin);

  ull n;
  int m, k;
  cin >> n >> m >> k;

  vector<set<ull>> SETS(m + 1);
  map<ull, set<int>> NUMS;

  while (k--) {
    string command;
    cin >> command;

    if (command == "ADD") {
      int set_num;
      ull num;
      cin >> num >> set_num;

      NUMS[num].insert(set_num);
      SETS[set_num].insert(num);
    } else if (command == "DELETE") {
      int set_num;
      ull num;
      cin >> num >> set_num;

      SETS[set_num].erase(SETS[set_num].find(num));
      NUMS[num].erase(NUMS[num].find(set_num));
    } else if (command == "CLEAR") {
      int set_num;
      cin >> set_num;

      for (auto num : SETS[set_num]) NUMS[num].erase(NUMS[num].find(set_num));
      SETS[set_num].clear();
    } else if (command == "LISTSET") {
      int set_num;
      cin >> set_num;

      if (SETS[set_num].size() == 0) {
        cout << -1 << endl;
        continue;
      }

      for (auto i : SETS[set_num]) cout << i << ' ';
      cout << endl;
    } else {
      ull num;
      cin >> num;

      if (NUMS[num].size() == 0) {
        cout << -1 << endl;
        continue;
      }

      for (auto i : NUMS[num]) cout << i << ' ';
      cout << endl;
    }
  }

  return 0;
}

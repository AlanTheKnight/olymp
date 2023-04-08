#include <bits/stdc++.h>
using namespace std;

#define FOR_N(i, n) for (int i = 0; i < n; i++)

const int INF = 100000000;

int main() {
  int n, k, p;
  cin >> n >> k >> p;

  vector<int> cars(p);
  map<int, vector<int>> next_h;

  FOR_N(i, p) {
    cin >> cars[i];
    next_h[cars[i]].push_back(i);
  }

  map<int, int> next;

  for (auto i : next_h) {
    for (int j = 0; j < i.second.size() - 1; j++) {
      next[i.second[j]] = i.second[j + 1];
    }
  }

    set<pair<int, int>> floor;
    set<int> floor_cars_only;
    map<int, int> next;

    for (auto car : cars) {
      // Если на полу есть место
      if (floor.size() < k) {
        if (floor_cars_only.find(car) == floor.end()) {
          // Если нет такой машинки, добавляем её
          floor.insert({);
        } else {
          // Обновляем next
        }
      }
    }
}

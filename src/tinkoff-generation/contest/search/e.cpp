#define FOR_N(i, n) for (int i = 0; i < n; i++)

#include <bits/stdc++.h>
using namespace std;

// Задача E: Массивы
// Даны два массива. Для каждого элемента второго массива
// определите, сколько раз он встречается в первом массиве.
//
// Формат входных данных
// Первая строка входных данных содержит одно число n (1≤N≤10^5) - количество
// элементов в первом массиве. Далее идет n целых чисел, не превосходящих по
// модулю 10^9 - элементы первого массива. Далее идет количество элементов m во
// втором массиве и m элементов второго массива с такими же ограничениями.

int count(int val, vector<int>& a) {
  auto low = lower_bound(a.begin(), a.end(), val);
  if (low == a.end() || *low != val) return 0;
  auto high = upper_bound(a.begin(), a.end(), val);
  return high - low;
}

int main() {
  int n, m;

  cin >> n;
  vector<int> a(n);
  FOR_N(i, n) cin >> a[i];

  sort(a.begin(), a.end());

  cin >> m;
  FOR_N(i, m) {
    int x;
    cin >> x;
    cout << count(x, a) << ' ';
  }
  cout << endl;
}

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[i] = {x, i + 1};
    }

    if (n == 1) {
        cout << 1 << ' ' << a[0].first << endl;
        cout << a[0].second << endl;
        return 0;
    }

    // Отсортируем игроков по возрастанию ПП
    sort(a.begin(), a.end(),
         [](const pair<int, int>& xa, const pair<int, int>& xb) {
             return xa.first < xb.first;
         });

    int j = 1,  // Игрок с сильнейшим ПП
        i = 0;  // Игрок с наименьшим ПП

    pair<long long, pair<int, int>> ans = {INT_MIN, {0, 0}};

    // Начальная сумма ПП с i по j
    long long sum = a[i].first + a[j].first;

    while (j < n) {
        // Если максимальный ПП не превосходит минимальную сумму ПП
        if (a[j].first <= a[i + 1].first + a[i].first) {
            if (sum > ans.first) {
                ans = {sum, {i, j}};
            }
            j++;
            sum += a[j].first;
        } else {
            sum -= a[i].first;
            i++;
        }
    }

    // Вывод ответа
    cout << ans.second.second - ans.second.first + 1 << ' ' << ans.first << ' '
         << endl;
    for (int i = ans.second.first; i <= ans.second.second; i++) {
        cout << a[i].second << endl;
    }
}

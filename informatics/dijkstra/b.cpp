// 27989461 OK 100

#include <bits/stdc++.h>

using namespace std;

#define FOR(var, n) for (size_t var = 0; (var) < (n); (var)++)
[[maybe_unused]] typedef pair<int, int> pair_int;
const int INF = 10000000;

/**
 * Дейкстра: восстановление пути
 *
 * Дан ориентированный взвешенный граф. Найдите кратчайший путь от одной заданной вершины до другой.
 *
 * В первой строке содержатся три числа: N, S и F (1 ≤ N ≤ 100, 1 ≤ S, F ≤ N), где N – количество вершин графа,
 * S – начальная вершина, а F – конечная. В следующих N строках вводится по N чисел, не превосходящих 100,
 * – матрица смежности графа, где -1 означает отсутствие ребра между вершинами, а любое неотрицательное число
 * – присутствие ребра данного веса. На главной диагонали матрицы записаны нули.
 *
 * Требуется вывести последовательно все вершины одного (любого) из кратчайших путей,
 * или одно число -1, если пути между указанными вершинами не существует.
 * */

int main() {
    int n, start, finish;
    cin >> n >> start >> finish;
    start--;
    finish--;

    set<pair_int> s;
    vector<int> dist(n, INF);
    vector<vector<int>> g(n, vector<int>(n));
    vector<int> prev(n, -1);

    FOR(i, n) {
        FOR(j, n) {
            cin >> g[i][j];
        }
    }

    s.insert({0, start});
    dist[start] = 0;

    while (!s.empty()) {
        int u = s.begin()->second;
        s.erase(s.begin());
        FOR(to, n) {
            if (g[u][to] != -1 && to != u) {
                int len = g[u][to];
                if (dist[to] > dist[u] + len) {
                    s.erase({dist[to], to});
                    dist[to] = dist[u] + len;
                    prev[to] = u;
                    s.insert({dist[to], to});
                }
            }
        }
    }

    if (dist[finish] == INF) {
        cout << -1 << endl;
        return 0;
    }

    int cur = finish;
    vector<int> ans(0);
    while (cur != -1) {
        ans.push_back(cur + 1);
        cur = prev[cur];
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) cout << i << ' ';
    cout << endl;
}

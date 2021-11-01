#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
using namespace std;


int main(int argc, char const *argv[])
{
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> dist(n, INF);
    queue<pair<int, int>> q;
    q.push({0, v[0]});
    dist[0] = 0;
    int m = 1;

    while (!q.empty()) {
        int u = q.front().first;
        int r = q.front().second;
        q.pop();

        // Не рассматриваем лианы, с которых
        // никуда нельзя прыгнуть
        if (r < d) continue;

        // Просматриваем все возможные переходы
        int possible = r / d; // Количество возможных переходов
        for (int i = 1; i <= possible; i++) {
            int to = u + i;
            if (to >= n) break;
            int to_dist = v[to];
            if (dist[to] > dist[u] + 1) {
                dist[to] = dist[u] + 1; // Новое расстояние
                m = max(m, to + 1); // Максимальный номер лианы
                q.push({to, to_dist});
            }
        }
    }

    // Выводим первую попавшуюся лиану,
    // до которой мы дошли
    cout << m << endl;
}


#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> coord;
typedef pair<coord, coord> v;

#define INF 10000000

int dist[51][51][51][51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // Координаты точки
    coord e;
    // Координаты машины
    coord a;
    vector<string> p(n);

    // Fill dist with INF
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < m; l++)
                {
                    dist[i][j][k][l] = INF;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        p[i] = s;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '.')
            {
                e = {i, j};
            }
            else if (s[j] == 'X')
            {
                a = {i, j};
            }
        }
    }

    queue<v> q;
    q.push({e, a});
    dist[e.first][e.second][a.first][a.second] = 0;
    while (!q.empty())
    {

        v cur = q.front();
        q.pop();

        int di[4] = {1, -1, 0, 0};
        int dj[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++)
        {
            // Координаты точки
            coord np = {cur.first.first + di[i], cur.first.second + dj[i]};

            // Границы поля + не стена
            if (
                np.first >= 0 && np.first < n &&
                np.second >= 0 && np.second < m &&
                p[np.first][np.second] != '#')
            {
                int new_dist =
                    dist[cur.first.first][cur.first.second][cur.second.first][cur.second.second] + 1;

                // Меняем местами автомобиль и пустое место
                coord x = cur.second;
                if (cur.second == np)
                {
                    x = cur.first;
                }

                if (dist[np.first][np.second][x.first][x.second] > new_dist)
                {
                    dist[np.first][np.second][x.first][x.second] = new_dist;
                    q.push({np, x});
                }
            }
        }
    }

    int ans = INF;
    if (n > 1)
    {
        ans = min(ans, dist[1][0][0][0]);
    }

    if (m > 1)
    {
        ans = min(ans, dist[0][1][0][0]);
    }

    if (ans == INF)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        cout << ans << endl;
    }
}
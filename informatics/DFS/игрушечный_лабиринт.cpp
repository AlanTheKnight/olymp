#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int h, w;
    cin >> h >> w;

    vector<vector<int>> dist(h + 2, vector<int>(w + 2, -1));
    vector<vector<int>> g(h + 2, vector<int>(w + 2));
    vector<pair<int, int>>

    // Заполняем поле, но делаем дополнительные стенки по краям, типо
    // 1 1 1 1 1 1 1
    // 1         1 1
    // 1   1 1   2 1
    // 1   2 1     1
    // 1     1     1
    // 1 1 1 1 1 1 1

    for (int y = 0; y <= h + 1; y++)
    {
        for (int x = 0; x <= w + 1; x++)
        {
            if (x == 0 || y == 0 || x == w + 1 || y == h + 1)
            {
                g[y][x] = 1;
            }
            else
            {
                cin >> g[y][x];
            }
            dist[y][x] = -1;
        }
    }

    cout << "Дистанции от начальной точки:" << endl;
    for (auto row : g)
    {
        for (auto cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    dist[1][1] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int y = p.first;
        int x = p.second;

        cout << "Текущая вершина: " << y << ' ' << x << endl;

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++)
        {
            int nCol = x + dx[i];
            int nRow = y + dy[i];

            while (g[nRow][nCol] == 0)
            {
                nCol += dx[i];
                nRow += dy[i];
            }

            if (g[nRow][nCol] == 1) {
                nCol -= dx[i];
                nRow -= dy[i];
            }

            if (dist[nRow][nCol] == -1) {
                dist[nRow][nCol] = dist[y][x] + 1;
                q.push(make_pair(nRow, nCol));
            }
        }
    }

    cout << "Дистанции от начальной точки:" << endl;
    for (auto row : dist)
    {
        for (auto cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}

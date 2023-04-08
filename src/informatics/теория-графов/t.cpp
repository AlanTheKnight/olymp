#include <bits/stdc++.h>
using namespace std;

struct Answer
{
    int t1, t2, t3, t4;

    Answer(int a = -1, int b = -1, int c = -1, int d = -1)
    {
        t1 = a, t2 = b, t3 = c, t4 = d;
    }

    void update(int _t1 = -1, int _t2 = -1, int _t3 = -1, int _t4 = -1)
    {
        t1 = _t1, t2 = _t2, t3 = _t3, t4 = _t4;
    }

    void print()
    {
        int c = (t1 != -1) + (t2 != -1) + (t3 != -1) + (t4 != -1);
        cout << c << endl;
        if (t1 != -1)
            cout << t1 + 1 << " ";
        if (t2 != -1)
            cout << t2 + 1 << " ";
        if (t3 != -1)
            cout << t3 + 1 << " ";
        if (t4 != -1)
            cout << t4 + 1 << " ";
    }
};

int d[300301], b[300301];
int best = 0;
Answer res;
int cur, cur1, cur2, cur3;
vector<vector<pair<int, int>>> g;

// Перебор вершин
void go(int x, int y)
{
    cur = b[x] + b[y];

    // Путь состоит из двух вершин
    if (cur > best)
    {
        best = cur;
        res.update(x, y);
    }

    // Перебираем соседей вершины x
    for (int j = 0; j < d[x]; j++)
    {
        // Третья вершина
        int bx = g[x][j].second;

        // Пропускаем случай, когда вершина совпадает с уже выбранной
        if (bx == y)
            continue;

        // Путь состоит из 3 вершин
        cur2 = cur + b[bx];
        if (cur2 > best)
        {
            best = cur2;
            res.update(bx, x, y);
        }

        // Проверяем соседей вершины y
        for (int k = 0; k < d[y]; k++)
        {
            // Четвертая вершина
            int by = g[y][k].second;

            // Пропускаем случай, когда вершина совпадает с уже выбранной
            // или равна третьей вершине
            if (by == x || by == bx)
                continue;

            // Путь состоит из 4 вершин
            cur3 = cur2 + b[by];
            if (cur3 > best)
            {
                best = cur3;
                res.update(bx, x, y, by);
            }
        }
    }
}

int main()
{
    // freopen("tourist.in", "r", stdin);
    // freopen("tourist.out", "w", stdout);

    int V, E;
    cin >> V >> E;
    g.resize(V);                 // Граф
    vector<pair<int, int>> e(E); // Вектор ребер

    for (int i = 0; i < V; i++)
    {
        cin >> b[i];
        // Проверка случая, когда лучший путь состоит из 1 вершины
        if (b[i] > best)
        {
            best = b[i];
            res.update(i);
        }
    }

    for (int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(make_pair(b[y], y));
        g[y].push_back(make_pair(b[x], x));
        e[i] = make_pair(x, y);
    }

    // Так как в графе хранятся и уровни красоты, то
    // можно просто отсортировать соседей каждый вершины
    for (int i = 0; i < V; i++)
    {
        sort(g[i].rbegin(), g[i].rend());
        d[i] = g[i].size();
        // Нам нужно не больше 7 соседей
        if (d[i] > 7)
            d[i] = 7;
    }

    for (int i = 0; i < E; i++)
    {
        int x = e[i].first, y = e[i].second;
        go(x, y);
        swap(x, y);
        go(x, y);
    }

    res.print();

    return 0;
}

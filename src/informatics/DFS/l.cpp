#include <bits/stdc++.h>
using namespace std;

vector<int> f;
vector<int> w;
int counter, n;

void dfs(int u, int start)
{
    if (f[u] == start)
    {
        counter++;
        return;
    }

    if (f[u] == -1)
    {
        f[u] = start;
        dfs(w[u], start);
    }
}

int main()
{
    cin >> n;

    w.resize(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        w[i] = x;
    }

    // Необходимо посчитать количество циклов в графе, где у
    // каждой вершины ровно одно ребро.

    f.assign(n, -1);
    counter = 0;

    for (int i = 0; i < n; i++)
    {
        // Данная вершина еще не посещена
        if (f[i] == -1)
            dfs(i, i);
    }

    cout << counter << endl;
}
#include <iostream>
#include <vector>
using namespace std;

int circle(int x1, int y1, int x2, int y2, int r1, int r2)
{
    int distSq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    int radSumSq = (r1 + r2) * (r1 + r2);
    return distSq <= radSumSq;
}

struct Apple
{
    int x, y, z, r;
    Apple(int _x, int _y, int _z, int _r) : x(_x), y(_y), z(_z), r(_r) {}
    Apple() {}
};

vector<vector<int>> g;
vector<bool> visited;

void dfs(int v, int& cnt)
{
    visited[v] = true;
    cnt++;
    for (auto u : g[v])
    {
        if (!visited[u])
            dfs(u, cnt);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<Apple> apples(n);
    for (int i = 0; i < n; i++)
    {
        int x, y, z, r;
        cin >> x >> y >> z >> r;
        Apple d(x, y, z, r);
        apples[i] = d;
    }

    g.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            Apple first = apples[i], second = apples[j];
            if (circle(first.x, first.y, second.x, second.y, first.r, second.r) && first.z >= second.z)
                g[i].push_back(j);
        }
    }

    visited.resize(n);
    int count = 0;
    dfs(0, count);

    cout << count << endl;
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i])
        {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}

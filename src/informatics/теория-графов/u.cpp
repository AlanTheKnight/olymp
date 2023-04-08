#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges.push_back({u, v});
    }

    vector<int> topsort(n);
    for (int i = 0; i < n; i++)
        cin >> topsort[i];

    vector<int> indexes(n);
    for (int i = 0; i < n; i++)
        indexes[topsort[i] - 1] = i;

    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        // If there's node from u to v, u should appear before v
        if (indexes[u] > indexes[v])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9

int main()
{

    string x;
    int k;
    cin >> x >> k;

    int y = (x[0] - '0') % k;
    for (size_t i = 1; i < x.size(); i++)
    {
        y = (y * 10 + (x[i] - '0')) % k;
    }

    vector<int> dist(k + 1, INF);
    vector<pair<int, int>> prev(k + 1);

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    dist[y] = 0;

    queue<int> q;
    q.push(y);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < n; i++)
        {
            int next = (cur * 10 + a[i]) % k;
            if (dist[next] > dist[cur] + 1)
            {
                dist[next] = dist[cur] + 1;
                prev[next] = {cur, a[i]};
                q.push(next);
            }
        }
    }

    if (dist[0] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        if (dist[0] == 0)
        {
            cout << x << endl;
            return 0;
        }

        vector<int> path;
        int cur = 0;
        while (prev[cur].first != y)
        {
            path.push_back(prev[cur].second);
            cur = prev[cur].first;
        }

        path.push_back(prev[cur].second);
        reverse(path.begin(), path.end());

        cout << x;
        for (size_t i = 0; i < path.size(); i++)
        {
            cout << path[i];
        }
        cout << endl;
    }
}
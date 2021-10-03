#include <bits/stdc++.h>

using namespace std;

queue<int> q;
vector<int> p(10000);
vector<int> dist(10000, -1);

vector<int> processNum(int n)
{
    vector<int> res;
    if (n / 1000 != 9)
    {
        res.push_back(( n / 1000 != 9) ? n + 1000 : n);
    }
    if (n % 10 != 1)
    {
        res.push_back((n % 10 != 1) ? n - 1 : n);
    }
    res.push_back((n % 1000) * 10 + n / 1000);
    res.push_back((n % 10) * 1000 + n / 10);

    return res;
}

void bfs(int n)
{
    dist[n] = 0;
    q.push(n);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        vector<int> options = processNum(u);

        for (auto v : options)
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
                p[v] = u;
            }
        }
    }
    
}

int main()
{
    int n, k;
    cin >> n >> k;

    bfs(n);

    if (dist[k] == -1) {
        return 0;
    }

    vector<int> ans;
    int i = k;
    while (i != n)
    {
        ans.push_back(i);
        i = p[i];
    }
    ans.push_back(n);

    reverse(ans.begin(), ans.end());

    for (auto i : ans)
    {
        cout << i << '\n';
    }
    cout << endl;

    

    return 0;
}
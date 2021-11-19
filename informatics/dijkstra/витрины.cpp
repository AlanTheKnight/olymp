#include <bits/stdc++.h>
using namespace std;

const int INF = 10000000;

bool isValid(pair<int, int> coords) {
    return coords.first >= 0 && coords.second >= 0 && coords.first < 
}

int main(int argc, char const *argv[])
{
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    pair<int, int> small[x];
    for (int i = 0; i < x; i++)
    {
        cin >> small[i].first >> small[i].second;
    }

    vector<vector<int>> d(101, vector<int>(101, INF));
    set<pair<pair<int, int>, int>> q;

    d[0][0] = 0;
    q.insert({{0, 0}, 0});

    while (!q.empty()) {
        auto cur = *q.begin();
        q.erase(q.begin());
        pair<int, int> curCoords = cur.first;
        int curL = cur.second;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

    }


    return 0;
}

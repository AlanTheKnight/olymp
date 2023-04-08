#include <bits/stdc++.h>
using namespace std;

#define INF 10000000
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define FOR(var, n) for (size_t var = 0; (var) < (n); (var)++)

int height, width, k, x;

bool isValid(pii coords) {
    return coords.first >= 0 && coords.second >= 0 &&
           coords.first <= width - k && coords.second < height;
}

int main() {
    cin >> width >> height >> k >> x;
    vector<pii> small(x);
    for (int i = 0; i < x; i++) cin >> small[i].first >> small[i].second;

    // Предподсчет
    set<pii> smalls_set(small.begin(), small.end());
    map<pii, int> small_cache;
    FOR(row, height) {
        FOR(col, width - k + 1) {
            pii cur = make_pair(col, row);
            FOR(step, k) {
                if (smalls_set.find(make_pair(cur.first + step, cur.second)) !=
                    smalls_set.end()) {
                    small_cache[cur]++;
                }
            }
        }
    }

    vvi d(101, vector<int>(101, INF));
    set<pair<int, pii>> q;
    map<pii, pii> prev;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    d[0][0] = 0;
    q.insert({0, {0, 0}});

    while (!q.empty()) {
        auto a = *q.begin();
        q.erase(q.begin());

        FOR(i, 4) {
            pii c = make_pair(a.second.first + dx[i], a.second.second + dy[i]);
            int w = 0;

            if (isValid(c)) {
                if (i == 0 || i == 1) {
                    // Up/down
                    // for (auto s : small) {
                    //     if (s.second == c.second && s.first >= c.first &&
                    //         s.first <= c.first + k - 1) {
                    //         w++;
                    //     }
                    // }
                    w += small_cache[c];
                } else if (i == 2) {
                    // Right
                    if (smalls_set.find(make_pair(c.first + k - 1, c.second)) !=
                        smalls_set.end())
                        w++;
                } else {
                    // Left
                    if (smalls_set.find(make_pair(c.first, c.second)) !=
                        smalls_set.end())
                        w++;
                }

                if (w + a.first < d[c.first][c.second]) {
                    q.erase(make_pair(d[c.first][c.second], c));
                    d[c.first][c.second] = w;
                    prev[c] = a.second;
                    q.insert(make_pair(d[c.first][c.second], c));
                }
            }
        }
    }

    cout << d[width - k][height - 1] << endl;

    pii cur = make_pair(width - k, height - 1);
    vector<char> path;
    while (!(cur.second == 0 && cur.first == 0)) {
        int xd = cur.first - prev[cur].first,
            yd = cur.second - prev[cur].second;

        if (xd > 0)
            path.push_back('R');
        else if (xd < 0)
            path.push_back('L');

        if (yd > 0)
            path.push_back('U');
        else if (yd < 0)
            path.push_back('D');

        cur = prev[cur];
    }

    for (int i = path.size() - 1; i >= 0; i--) cout << path[i];
    cout << endl;

    return 0;
}

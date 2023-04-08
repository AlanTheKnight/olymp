#include <bits/stdc++.h>
using namespace std;

#define FOR(var, start, end) for (size_t var = start; var <= end; var++)
#define FOR_N(var, n) for (int var = 0; var < n; var++)
#define FOR_STEP(var, start, end, step) \
    for (size_t var = start; var <= end; var += step)

struct Move {
    int v, x, y;

    friend bool operator<(const Move& a, const Move& b) { return a.v < b.v; }

    bool valid(Move& other) {
        return (this->x == other.x || this->y == other.y ||
                ((this->x + this->y) % 2) == ((other.x + other.y) % 2));
    }
};

int main() {
    int n, m, k, cnt = 0;
    cin >> m >> n >> k;
    vector<Move> moves;
    FOR_N(i, m) {
        FOR_N(j, n) {
            int x;
            cin >> x;
            if (x > 0) {
                moves.push_back(Move({x, i, j}));
                cnt++;
            }
        }
    }

    if (k != moves.size() - 1) {
        cout << "Wrong board" << endl;
        return 0;
    }

    sort(moves.begin(), moves.end());

    vector<vector<int>> ans(m, vector<int>(n, 0));

    for (int i = 0; i < k; i++) {
        if (!moves[i].valid(moves[i + 1])) {
            cout << "Wrong board" << endl;
            return 0;
        }

        ans[moves[i].x][moves[i].y] = i + 1;
    }
    ans[moves[k].x][moves[k].y] = k + 1;

    for (auto row : ans) {
        for (auto col : row) cout << col << ' ';
        cout << endl;
    }
}
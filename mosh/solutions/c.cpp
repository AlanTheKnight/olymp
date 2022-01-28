#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define matrix vector<vector<bool>>
#define INF 1000000

void print_matrix(matrix m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}

pair<int, matrix> action(matrix old, int row, int col) {
    int cnt = 0;
    for (int i = 0; i < old.size(); i++) {
        for (int j = 0; j < old.size(); j++) {
            if (i == row || j == col) old[i][j] = !old[i][j];
            if (old[i][j]) cnt++;
        }
    }
    return {cnt, old};
}

struct data {
    int count;
    int step;
    matrix m;
    vector<pair<int, int>> path;
};

void solve() {
    int n, cnt;
    cin >> n;
    matrix m(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            m[i][j] = (bool)x;
            if (x) cnt++;
        }
    }

    if (cnt == 0) {
        cout << 0 << endl;
        print_matrix(m);
        return;
    }

    queue<data> q;
    q.push({cnt, 0, m});
    data answer;
    bool keep_searching = true;

    while (keep_searching) {
        data front = q.front();
        q.pop();

        if (front.count == 0) {
            keep_searching = false;
            answer = front;
            continue;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                auto res = action(front.m, i, j);
                vector<pair<int, int>> path = front.path;
                path.push_back({i, j});
                q.push({res.first, front.step + 1, res.second, path});
            }
        }
    }

    cout << answer.step << endl;
    for (auto p : answer.path) {
        cout << p.first << " " << p.second << endl;
    }
}

int main() {
    freopen("../tests/c1.txt", "r", stdin);

    int t;
    cin >> t;
    while (t--) {
        cout << "Test case #" << t + 1 << ":\n";
        solve();
    }
}

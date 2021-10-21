#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;

vector<bool> used;
int g[MAX][MAX];
int n;

void dfs(int u) {
    used[u] = true;
    for (int i = 0; i < n; i++) {
        if (g[u][i] == 1 && !used[i]) {
            dfs(i);
        }
    }
}


int main() {
    cin >> n;
    int a = 0;
    int s = 0;
    used.assign(n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            if (g[i][j] == 1) {
                a++;
                if (!s)
                    s = i;
            }
        }
    }
    dfs(s);
    cout << ((a / 2 == n - 1 && find(used.begin(), used.end(), false) == used.end()) ? "YES" : "NO") << endl;
    return 0;
}


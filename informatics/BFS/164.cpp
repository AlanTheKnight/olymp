#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;

bool used[MAX] = {false};
int g[MAX][MAX];
int n;
int c = 1;

void dfs(int u) {
    used[u] = true;
    for (int i = 0; i < n; i++) {
        if (g[u][i] == 1 && !used[i]) {
            c++;
            dfs(i);
        }
    }
}


int main() {
    int s;
    cin >> n >> s;
    s--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    dfs(s);
    cout << c << endl;
    return 0;
}


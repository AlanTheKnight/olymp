#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;

enum Colors {
    WHITE = 0,
    GREY = 1,
    BLACK = 2
};

bool used[MAX] = {false};
int colored[MAX] = {Colors::WHITE};
int g[MAX][MAX];
int n;
bool ans = false;


void dfs(int u) {
    used[u] = true;
    colored[u] = Colors::GREY;
    for (int i = 0; i < n; i++) {
        if (g[u][i] == 1) {
            if (colored[i] == Colors::WHITE) {
                dfs(i);
            }
            if (colored[i] == Colors::GREY) {
                ans = true;
                return;
            }
        }
    }
    colored[u] = Colors::BLACK;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
            if (ans) break;
        }
    }

    cout << (int) ans << endl;
    return 0;
}


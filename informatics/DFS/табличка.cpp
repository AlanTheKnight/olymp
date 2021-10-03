#include <bits/stdc++.h>
#define INF 1000000
using namespace std;


struct Cell 
{
    int x, y;
    Cell(int x, int y): x(x), y(y) {}
};


int main() {
    int h, w;
    cin >> h >> w;

    queue<Cell> q;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    

    int a[h][w];
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            if (a[y][x] == 1) {
                dist[y][x] = 0;
                q.push(Cell(x, y));
            }
        }
    }

    while (!q.empty()) {
        Cell c = q.front();
        q.pop();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nx = c.x + dx[i];
            int ny = c.y + dy[i];
            if (nx >= 0 && nx < w && ny >= 0 && ny < h && dist[ny][nx] > dist[c.y][c.x] + 1) {
                dist[ny][nx] = dist[c.y][c.x] + 1;
                q.push(Cell(nx, ny));
            }
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cout << dist[y][x] << " ";
        }
        cout << endl;
    }
}
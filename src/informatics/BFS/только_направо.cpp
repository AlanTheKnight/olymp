#include <bits/stdc++.h>
using namespace std;

struct Move
{
    int row, col, direction;
    Move(int d, int r, int c) : direction(d), row(r), col(c) {}
};

int main()
{
    int h, w;
    scanf("%d %d\n", &h, &w);

    vector<vector<char>> g(h, vector<char>(w));
    vector<vector<vector<int>>> dist(4, vector<vector<int>>(h, vector<int>(w, -1)));

    int start_row, start_col, end_row, end_col;

    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            char x;
            scanf("%c", &x);
            if (x == 'S')
            {
                start_row = row;
                start_col = col;
                g[row][col] = ' ';
            }
            else if (x == 'F')
            {
                end_row = row;
                end_col = col;
                g[row][col] = ' ';
            }
            else if (x == 'X')
            {
                g[row][col] = 'X';
            }
            else
            {
                g[row][col] = ' ';
            }
        }
        char endl = '\n';
        scanf("%c", &endl);
    }

    queue<Move> q;

    // Перед началом движения мы не знаем направление, поэтому
    // перебираем все варианты

    for (int i = 0; i < 4; i++)
    {
        q.push(Move(i, start_row, start_col));
        dist[i][start_row][start_col] = 0;
    }

    while (!q.empty())
    {
        Move m = q.front();
        q.pop();

        if (m.row == end_row && m.col == end_col)
        {
            cout << dist[m.direction][m.row][m.col] << endl;
            return 0;
        }

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {-1, 0, 1, 0};

        for (int i = 0; i < 2; i++)
        {
            int nd = (m.direction + i) % 4;
            int nCol = m.col + dx[nd];
            int nRow = m.row + dy[nd];

            if (g[nRow][nCol] == ' ' && dist[nd][nRow][nCol] == -1)
            {
                q.push(Move(nd, nRow, nCol));
                dist[nd][nRow][nCol] = dist[m.direction][m.row][m.col] + 1;
            }
        }
    }
}

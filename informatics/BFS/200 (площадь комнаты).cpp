#include <iostream>
using namespace std;

int dfs(int n, int col, int row, char *F, bool *visited)
{
    int res = 0;
    visited[row * n + col] = true;

    if (F[row * n + col] == '.')
        res++;
    else
        return res;

    pair<int, int> moves[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for (int i = 0; i < 4; i++)
    {
        int nCol = col + moves[i].first;
        int nRow = row + moves[i].second;
        if (nCol >= 0 && nCol < n && nRow >= 0 && nRow < n && !visited[n * nRow + nCol])
        {
            res += dfs(n, nCol, nRow, F, visited);
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    char F[n * n];
    bool visited[n * n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> F[i * n + j];
            visited[i * n + j] = false;
        }
    }

    int row, col;
    cin >> row >> col;
    row--;
    col--;

    int square = dfs(n, col, row, F, visited);

    cout << square << endl;

    return 0;
}
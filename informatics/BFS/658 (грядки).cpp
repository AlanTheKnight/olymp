#include <iostream>
using namespace std;

int dfs(int height, int width, int col, int row, char *F, bool *visited)
{
    int res = 0;
    visited[row * width + col] = true;

    if (F[row * width + col] == '#')
        res++;
    else
        return res;

    pair<int, int> moves[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for (int i = 0; i < 4; i++)
    {
        int nCol = col + moves[i].first;
        int nRow = row + moves[i].second;
        if (nCol >= 0 && nCol < width && nRow >= 0 && nRow < height && !visited[width * nRow + nCol])
        {
            res += dfs(height, width, nCol, nRow, F, visited);
        }
    }
    return res;
}

int main()
{
    int height, width;
    cin >> height >> width;

    char F[height * width];
    bool visited[height * width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cin >> F[i * width + j];
            visited[i * width + j] = false;
        }
    }

    int count = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (!visited[i * width + j]) {
                if (dfs(height, width, j, i, F, visited) > 0) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
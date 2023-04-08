#include <bits/stdc++.h>
using namespace std;

#define FOR(var, start, end) for (size_t var = start; var <= end; var++)
#define FOR_N(var, n) for (size_t var = 0; var < n; var++)
#define FOR_STEP(var, start, end, step) for (size_t var = start; var <= end; var += step)

vector<vector<int>> g;
vector<vector<bool>> visited;

struct cell
{
    int row = 1, col = 1;
    cell(int _row, int _col) : row{_row}, col{_col} {}
    cell() {}
    int val();
    void mark();
    bool marked();
};

int cell::val()
{
    return g[this->row][this->col];
}

void cell::mark()
{
    visited[this->row][this->col] = true;
}

bool cell::marked()
{
    return visited[this->row][this->col];
}

size_t counter;

bool advance(cell c)
{
    if (c.marked())
        return false;
    c.mark();

    // Shows if group has at least one neighbour
    // with lower value.
    bool flag = false;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    FOR_N(i, 4)
    {
        cell n = cell(c.row + dy[i], c.col + dx[i]);
        if (n.val() < c.val())
        {
            flag = true;
            continue;
        }

        if (!n.marked() && n.val() == c.val())
        {
            flag = flag || advance(n);
        }
    }

    return flag;
}

/*
    Find a cell or a group of cells that
    don't have any neighbours with lower
    values.
*/
void dfs(cell c)
{
    if (c.marked())
        return;
    c.mark();

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    FOR_N(i, 4)
    {
        cell n = cell(c.row + dy[i], c.col + dx[i]);
        if (n.val() < c.val())
        {
            return;
        }

        if (n.val() == c.val())
        {
            bool res = advance(n);
            if (res)
                return;
        }
    }

    counter += 1;
}

int main(int argc, char const *argv[])
{
    int n, // Height
        m; // Width
    cin >> n >> m;

    g.assign(n + 2, vector<int>(m + 2));
    visited.assign(n + 2, vector<bool>(m + 2, false));

    FOR(i, 0, n + 1)
    {
        FOR(j, 0, m + 1)
        {
            if (i == 0 || i == n + 1 || j == 0 || j == m + 1)
                g[i][j] = 10001;
            else
                cin >> g[i][j];
        }
    }

    counter = 0;

    FOR(row, 1, n)
    {
        FOR(col, 1, m)
        {
            if (!visited[row][col])
            {
                dfs(cell(row, col));
            }
        }
    }

    cout << counter << endl;

    return 0;
}
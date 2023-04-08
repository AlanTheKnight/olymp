#include <bits/stdc++.h>
using namespace std;

void search(int y, int n, int &count, bool *col, bool *diag1, bool *diag2)
{
    if (y == n)
    {
        count++;
        return;
    }

    for (int x = 0; x < n; x++)
    {
        if (col[x] || diag1[x + y] || diag2[x - y + n])
            continue;
        col[x] = diag1[x + y] = diag2[x - y + n] = true;
        search(y + 1, n, count, col, diag1, diag2);
        col[x] = diag1[x + y] = diag2[x - y + n] = false;
    }
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    bool col[n], diag1[2 * n], diag2[2 * n];
    memset(col, false, sizeof col);
    memset(diag1, false, sizeof diag1);
    memset(diag2, false, sizeof diag2);
    int count = 0;
    search(0, n, count, col, diag1, diag2);
    cout << count << endl;
    return 0;
}

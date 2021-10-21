#include <bits/stdc++.h>
using namespace std;

int n = 8;

struct Cell
{
    int x, y;
    int plain()
    {
        return (this->y - 1) * n + this->x - 1;
    };
    bool valid()
    {
        return this->y > 0 && this->x > 0 && this->y <= n && this->x <= n;
    }
    void move(int mx, int my)
    {
        this->y += my;
        this->x += mx;
    }

    bool operator==(const Cell &c2) const
    {
        return this->x == c2.x && this->y == c2.y;
    }
    Cell(int x, int y) : x(x), y(y) {}
};

int main()
{
    char x;
    int y;
    cin >> x >> y;
    int sx = x - 'a' + 1;
    Cell start(sx, y);

    cin >> x >> y;
    int ex = x - 'a' + 1;
    Cell start2(ex, y);

    vector<int> dist1(64, 1000000);
    vector<int> dist2(64, 1000000);

    queue<Cell> q;

    dist1[start.plain()] = 0;
    q.push(start);
    while (!q.empty())
    {
        Cell cur = q.front();
        q.pop();

        int movesX[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int movesY[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

        for (int i = 0; i < 8; i++)
        {
            int mX = movesX[i], mY = movesY[i];
            Cell newMove(cur);
            newMove.move(mX, mY);
            if (newMove.valid())
            {
                if (dist1[newMove.plain()] > dist1[cur.plain()] + 1)
                {
                    dist1[newMove.plain()] = dist1[cur.plain()] + 1;
                    q.push(newMove);
                }
            }
        }
    }

    queue<Cell> q2;
    dist2[start2.plain()] = 0;
    q2.push(start2);
    while (!q2.empty())
    {
        Cell cur = q2.front();
        q2.pop();

        if (dist2[cur.plain()] == dist1[cur.plain()])
        {
            cout << dist1[cur.plain()] << endl;
            return 0;
        }

        int movesX[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int movesY[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

        for (int i = 0; i < 8; i++)
        {
            int mX = movesX[i], mY = movesY[i];
            Cell newMove(cur);
            newMove.move(mX, mY);
            if (newMove.valid())
            {
                if (dist2[newMove.plain()] > dist2[cur.plain()] + 1)
                {
                    dist2[newMove.plain()] = dist2[cur.plain()] + 1;

                    q2.push(newMove);
                }
            }
        }
    }

    cout << -1 << endl;
}

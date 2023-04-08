#include <bits/stdc++.h>
using namespace std;

int n;

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
};

int main()
{
    cin >> n;

    Cell start, end;
    cin >> start.x >> start.y;
    cin >> end.x >> end.y;

    vector<Cell> pred(n * n);
    vector<int> dist(n * n, 1000000);
    queue<Cell> q;

    dist[start.plain()] = 0;
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
                if (dist[newMove.plain()] > dist[cur.plain()] + 1)
                {
                    dist[newMove.plain()] = dist[cur.plain()] + 1;
                    pred[newMove.plain()] = cur;
                    q.push(newMove);
                }
            }
        }
    }

    cout << dist[end.plain()] << endl;

    vector<Cell> way;

    Cell x = end;
    while (!(x == start))
    {
        way.push_back(x);
        x = pred[x.plain()];
    }

    cout << start.x << ' ' << start.y << endl;

    for (int i = way.size() - 1; i >= 0; i--)
    {
        cout << way[i].x << ' ' << way[i].y << endl;
    }
}

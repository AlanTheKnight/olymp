#include <bits/stdc++.h>
using namespace std;

int movesX[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int movesY[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main()
{
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // Самый простой случай
    if (x1 == x2 && y1 == y2)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<pair<int, int>> start_black;

    // Если мы стоим на белой клетке поля
    if ((abs(x1) + abs(y1)) % 2 == 0)
    {
        for (int i = 0; i < 8; i++)
        {
            int nX = x1 + movesX[i], nY = y1 + movesY[i];
            if (nX == x2 && nY == y2)
            {
                cout << 1 << endl;
                cout << x2 << ' ' << y2 << endl;
                return 0;
            }
            start_black.push_back(make_pair(nX, nY));
        }

        if ((abs(x2) + abs(y2)) % 2 == 1) // Финальная клетка черная
        {
            vector<vector<int>> solutions;
            for (auto p : start_black)
            {
                // Решение за 1 ход всегда будет лучшим
                if (abs(p.first - x2) == abs(p.second - y2))
                {
                    cout << 2 << endl;
                    cout << p.first << ' ' << p.second << ' ' << x2 << ' ' << y2 << endl;
                    return 0;
                }

                // Решение за 2 хода
                int s0 = p.first + p.second + x2 - y2;
                int n0 = p.first + p.second - x2 + y2;
                s0 /= 2;
                n0 /= 2;
                solutions.push_back({p.first, p.second, s0, n0, x2, y2});
            }

            cout << 3 << endl;
            for (auto i : solutions)
            {
                cout << i[0] << ' ' << i[1] << ' ' << i[2] << ' ' << i[3] << ' ' << i[4] << ' ' << i[5] << endl;
                return 0;
            }
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }
    else
    {
        // Если стоим на черной и финальная клетка - черная
        if ((abs(x2) + abs(y2)) % 2 == 1)
        {
            // Решение за 1 ход
            if (abs(x1 - x2) == abs(y1 - y2))
            {
                cout << 1 << endl;
                cout << x2 << ' ' << y2 << endl;
                return 0;
            }

            // Решение за 2 хода
            int s0 = x1 + y1 + x2 - y2;
            int n0 = x1 + y1 - x2 + y2;
            s0 /= 2;
            n0 /= 2;
            cout << 2 << endl;
            cout << s0 << ' ' << n0 << ' ' << x2 << ' ' << y2 << endl;
            return 0;
        }

        // Если финальная клетка белая, то невозможно
        cout << -1 << endl;
        return 0;
    }

    return 0;
}
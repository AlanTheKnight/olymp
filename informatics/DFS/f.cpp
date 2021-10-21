#include <vector>
#include <iostream>

using namespace std;

bool ggEz = false;

enum Color
{
    NOT_VISITED, // Node wasn't visited
    BLACK,       // First team
    RED,         // Second team
};

Color opposite(Color c)
{
    if (c == BLACK)
        return RED;
    else if (c == RED)
        return BLACK;
    return NOT_VISITED;
}

vector<vector<int>> graph;
vector<Color> color;

void dfs(int t)
{
    for (auto i : graph[t])
    {
        // Если вершина еще не посещена, красим в противоположный цвет
        // и запускаем такой же dfs
        if (color[i] == NOT_VISITED)
        {
            color[i] = opposite(color[t]);
            dfs(i);
        }
        // Если цвет одинаковый, то что-то не так
        else if (color[i] == color[t])
        {
            ggEz = true;
            return;
        }
        // Если цвет противоположный, то все окей
    }
}

int main()
{
    int m, n;
    cin >> n >> m;
    graph.resize(n);
    color.assign(n, NOT_VISITED);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        if (color[i] == NOT_VISITED)
        {
            color[i] = RED;
            dfs(i);
            if (ggEz)
                break;
        }
    }

    if (ggEz)
    {
        cout << "NO" << endl;
        return 0;
    }
    
    cout << "YES" << endl;
    // Пробуем вывести людей за первым столом
    for (int i = 0; i < color.size(); i++)
    {
        if (color[i] == RED)
            cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
}
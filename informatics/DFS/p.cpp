#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> visited(62, vector<bool>(62, false));

bool getInput()
{
    string s;
    cin >> s;
    if (s == "EMPTY")
        return true;
    return false;
}

map<string, pair<int, int>> moves = {
    {"NORTH", {0, 1}},
    {"WEST", {-1, 0}},
    {"SOUTH", {0, -1}},
    {"EAST", {1, 0}}};

void dfs(int x, int y)
{
    bool f;
    visited[x][y] = true;
    if (!visited[x][y - 1])
    {
        cout << "NORTH" << endl;
        if (getInput())
        {
            dfs(x, y - 1);
            cout << "SOUTH" << endl;
            f = getInput();
        }
    }
    if (!visited[x][y + 1])
    {
        cout << "SOUTH" << endl;
        if (getInput())
        {
            dfs(x, y + 1);
            cout << "NORTH" << endl;
            f = getInput();
        }
    }
    if (!visited[x - 1][y])
    {
        cout << "WEST" << endl;
        if (getInput())
        {
            dfs(x - 1, y);
            cout << "EAST" << endl;
            f = getInput();
        }
    }
    if (!visited[x + 1][y])
    {
        cout << "EAST" << endl;
        if (getInput())
        {
            dfs(x + 1, y);
            cout << "WEST" << endl;
            f = getInput();
        }
    }
}

int main(int argc, char const *argv[])
{
    dfs(31, 31);
    cout << "DONE" << endl;
    return 0;
}

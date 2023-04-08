#include <bits/stdc++.h>
using namespace std;

int main() {
    int teams, n;
    cin >> teams >> n;
    vector<int> result(teams, 0);
    vector<pair<int, string>> v;
    map<string, int> m;

    for (int i = 0; i < n; i++) {
        int team;
        string s;
        cin >> team >> s;
        m[s] = team;
    }

    for (auto i : m) {
        result[i.second - 1]++;
    }

    for (auto team : result) {
        cout << team << ' ';
    }
    cout << endl;
}
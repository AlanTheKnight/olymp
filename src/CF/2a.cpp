#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, score, max_score = INT_MIN;
    cin >> n;
    string name;
    map<string, int> scoreboard;
    pair<string, int> game[n];
    for (int i = 0; i < n; i++) {
        cin >> name >> score;
        game[i] = make_pair(name, score);
        scoreboard[name] += score;
    }

    for (auto player : scoreboard) {
        max_score = max(max_score, player.second);
    }

    map<string, int> cur;
    for (int i = 0; i < n; i++) {
        cur[game[i].first] += game[i].second;
        if (scoreboard[game[i].first] == max_score &&
            cur[game[i].first] >= max_score) {
            cout << game[i].first << endl;
            return 0;
        }
    }
}
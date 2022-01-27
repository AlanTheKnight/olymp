#include <bits/stdc++.h>
using namespace std;

#define card_up color.second.first
#define card_down color.second.second

int main() {
    int n;
    cin >> n;
    int goal = (n + 1) / 2;
    map<int, pair<int, int>> m;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        m[a].first++;
        if (a != b) m[b].second++;
    }

    int min_amount = INT_MAX;
    for (auto color : m) {
        if (color.second.first >= goal) {
            min_amount = 0;
            break;
        }

        if (card_up + card_down >= goal && card_down >= goal - card_up)
            min_amount = min(min_amount, goal - card_up);
    }

    cout << (min_amount == INT_MAX ? -1 : min_amount) << endl;

    return 0;
}

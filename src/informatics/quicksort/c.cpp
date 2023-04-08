#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> stations(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        stations[i] = {x, i + 1};
    };

    sort(stations.begin(), stations.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.first < b.first;
         });

    pair<int, int> minimum = {INT_MAX, 0};
    for (int i = 0; i < n; i++) {
        int dist =
            i < n - 1 ? stations[i + 1].first - stations[i].first : INT_MAX;
        if (dist < minimum.first) {
            minimum = {dist, stations[i].second};
        }
    }

    cout << minimum.second << endl;
}

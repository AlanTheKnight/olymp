#include <iostream>
#include <climits>
using namespace std;


int main() {
    int s, e;
    cin >> s >> e;
    int n, x; cin >> n;
    pair<int, int> p = {INT_MAX, INT_MAX}; // ближайший портал
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (abs(s - x) < p.first) {
            p.first = abs(s - x);
        }
        if (abs(e - x) < p.second) {
            p.second = abs(e - x);
        }
    }

    int basic = abs(s - e);
    int portal = p.first + p.second + 1;

    cout << min(basic, portal) << endl;
}

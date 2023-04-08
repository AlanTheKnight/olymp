#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>


int main() {
    int a, b, n;
    cin >> n;
    long long answer = 0;
    map<int, int> x, y;
    map<pii, int> m;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        answer += (x[a] + y[b] - m[{a, b}]);
        x[a]++;
        y[b]++;
        m[{a, b}]++;
    }

    cout << answer << endl;
}
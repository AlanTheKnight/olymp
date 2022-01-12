#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

vector<ll> coords;       // Coords of the queen
vector<ll> board_sizes;  // Board sizes vector

ll getAxes(size_t index) {
    ll axes = 0;
    for (auto side : board_sizes) {
        axes += side - 1;
    }
    return axes;
}

vector<ll> cache;

ll getDiagHelper(ull &b, int d) {
    ll minimal = 10000000LL;
    for (int i = 0; i < d; i++) {
        ll cur =
            (b & (1 << i)) == 0 ? coords[i] - 1 : board_sizes[i] - coords[i];
        minimal = min(minimal, cur);
    }
    return minimal;
}

ll getDiagonal(int d) {
    if (d == 1) return 0;

    ull b = 0;
    ll ans = 0;
    long double times = pow(2, d);
    for (int i = 0; i < times; i++) {
        ans += getDiagHelper(b, d);
        b++;
    }

    return ans + getDiagonal(d - 1);
}

ll solve(int d) {
    if (d == 1) return board_sizes[0] - 1;

    ll ans = getDiagonal(d);
    ans += getAxes(d);

    return ans;
}

int main() {
    // Dimention of the chess board
    int d;
    cin >> d;

    coords.resize(d);
    board_sizes.resize(d);
    cache.assign(d, -1);

    for (int i = 0; i < d; i++) {
        cin >> board_sizes[i];
    }

    for (int i = 0; i < d; i++) {
        cin >> coords[i];
    }

    cout << solve(d) << endl;
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

#define ll long long
#define ceil(x, y) ((x + y - 1) / y)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    ll ans = 0;

    long double end = ceil(1 + sqrt(1 + n * 4), 2);

    for (ll i = 1; i <= (ll) end; i++) {
        ll x = (n - i) / (i * i);
        ans += x;
    }

    cout << ans << endl;

    return 0;
}

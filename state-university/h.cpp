#include <bits/stdc++.h>
using namespace std;

#define FOR(var, start, end) for (size_t var = start; var <= end; var++)
#define FOR_N(var, n) for (size_t var = 0; var < n; var++)
#define FOR_STEP(var, start, end, step) \
    for (size_t var = start; var <= end; var += step)

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    ll ans = a[0];
    ll prev = a[0];
    for (int i = 1; i < n; i++) {
        
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();    
    }
}
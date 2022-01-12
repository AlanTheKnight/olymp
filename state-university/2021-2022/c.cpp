#include <bits/stdc++.h>
using namespace std;

#define FOR(var, start, end) for (size_t var = start; var <= end; var++)
#define FOR_N(var, n) for (size_t var = 0; var < n; var++)
#define FOR_STEP(var, start, end, step) \
    for (size_t var = start; var <= end; var += step)

#define ll long long
#define vi vector<int>

vi a;

void getSum(ll &s, vi &a, int start, int end) {
    if (start == 0) {
        FOR(i, 0, end) { s += a[i]; }
        return;
    }
}

int main() {
    // Boost IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    int n;
    cin >> n;
    a.resize(n);
    FOR_N(i, n) { cin >> a[i]; }

    // Sort nums vector
    sort(a.begin(), a.end());

    // Iterating polygons with i sides
    // starting from 3
    FOR(i, 3, n) {
        ll s = 0;
        int start = 0;
        int end = i - 2;

        getSum(s, a, start, end);

        while (end < n - 1) {
            // cout << "S[" << start << ", " << end << "] = " << s << " => ";
            // cout << s << (s > a[end + 1] ? " > " : " <= ") << a[end + 1] <<
            // endl;

            if (s > a[end + 1]) {
                cout << i << endl;
                return 0;
            }

            s -= a[start];
            start++;
            end++;
            s += a[end];
        }
    }

    cout << -1 << endl;

    return 0;
}

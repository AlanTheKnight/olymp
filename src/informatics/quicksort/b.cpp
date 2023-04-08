#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n % 2 == 1)
        sort(a.begin(), a.end());
    else
        sort(a.begin(), a.end(), greater<>());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (auto i : a) cout << i << endl;
}

#include <bits/stdc++.h>
using namespace std;

void remove_repetitions(vector<int>& v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int a, b;
    cin >> a;
    vector<int> f(a);
    for (int i = 0; i < a; i++) cin >> f[i];
    cin >> b;
    vector<int> s(b);
    for (int i = 0; i < b; i++) cin >> s[i];

    remove_repetitions(f);
    remove_repetitions(s);

    if (f.size() != s.size()) {
        cout << "NO" << endl;
        return 0;
    }
    
    for (int i = 0; i < f.size(); i++) {
        if (f[i] != s[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}

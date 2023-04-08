#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    multiset<int> s;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i;
    for (i = 0; i < k; i++) {
        s.insert(a[i]);
    }

    for (int l = 0; i < n; i++, l++) {
        cout << *s.begin() << " ";
        s.erase(s.find(a[l]));
        s.insert(a[i]);
    }
    cout << *s.begin() << endl;

    return 0;
}

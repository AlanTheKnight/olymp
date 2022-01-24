#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, l;
    cin >> n >> m >> l;

    multiset<int> bottles;
    multiset<int> used_bottles;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bottles.insert(x);
    }

    int i;
    for (i = 0; i < m; i++) {
        int note;
        cin >> note;
        if (used_bottles.find(note) != used_bottles.end()) {
            continue;
        }

        auto not_used_yet = bottles.upper_bound(note);
        if (not_used_yet != bottles.begin()) {
            not_used_yet--;
            int diff = abs(note - *not_used_yet);
            if (diff <= l) {
                l -= diff;
                used_bottles.insert(note);
                bottles.erase(not_used_yet);
            } else {
                break;
            }
        } else {
            break;
        }
    }

    cout << i << endl;
}
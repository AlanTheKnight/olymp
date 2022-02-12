#include <bits/stdc++.h>
using namespace std;

int getAns1(string s, string m) {
    int cnt = 0;
    for (auto num : s) {
        auto l = lower_bound(m.begin(), m.end(), num);
        if (l != m.end()) {
            m.erase(l);
            cnt++;
        }
    }
    return s.size() - cnt;
}

int getAns2(string s, string m) {
    int cnt = 0;
    for (auto num : s) {
        auto u = upper_bound(m.begin(), m.end(), num);
        if (u != m.end()) {
            m.erase(u);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, cnt1 = 0, cnt2 = 0;
    string s, m;
    cin >> n >> s >> m;
    sort(m.begin(), m.end());
    sort(s.begin(), s.end());
    cout << getAns1(s, m) << endl;
    cout << getAns2(s, m) << endl;
}

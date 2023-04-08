#include <bits/stdc++.h>
using namespace std;


int main() {
    set<int> s;
    while (true) {
        int t;
        cin >> t;
        if (!t) break;
        s.insert(t);
    }
    
    cout << s.size() << endl;
}
#include <map>
#include <iostream>
#include <string>
#include <set>
using namespace std;



int main() {
    int n;
    string name;
    map<string, int> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name;
        m[name] = i;
    }

    set<pair<int, string>> s;
    for (auto i : m) {
        s.insert(make_pair(i.second, i.first));
    }

    for (auto i = s.rbegin(); i != s.rend(); i++) {
        cout << (*i).second << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0 ; i < n; i++) cin >> a[i];

    vector<int> d = {a[0] - 1};
    for (int i = 0 ; i < n - 1; i ++) 
        d.push_back(a[i + 1] - a[i] - 1);
    
    cout << (accumulate(d.begin(), d.end(), 0) % 2 == 1 ? "First" : "Second") << endl;
}

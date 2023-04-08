#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    string s;
    getline(cin, s);
    int ans = 1, c = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i - 1] == s[i]) {
            c++;
            if (ans < c) ans = c;
        }
        else c = 1;
    }
    cout << ans << endl;
    return 0;
}

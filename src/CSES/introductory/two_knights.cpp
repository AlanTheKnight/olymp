#define ll long long
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int k; cin >> k;
    for (ll n = 1; n <= k; n++) {
        cout << (n*n*(n*n-1) - 48 - (n-4)*16 - (n-4)*24 - (n-4)*(n-4)*8) / 2 << endl;
    }
    return 0;
}

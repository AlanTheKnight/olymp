#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    long n, s = 0, a;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a;
        s += a;
    }
    cout << ((1 + n) * n / 2) - s << endl;
    return 0;
}

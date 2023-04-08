#define ll long long

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    const bool n_even = (n % 2 == 0);
    ll s = (1 + n) * n / 2;
    if (
        (n % 2 == 0) && ((s / (n + 1)) % 2 == 1) ||
        (n % 2 == 1) && ((s / n) % 2 == 1))
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        vector<ll> set1, set2;
        s /= 2LL;
        while (n)
        {
            if (s - n >= 0)
            {
                set1.push_back(n);
                s -= n;
            }
            else
            {
                set2.push_back(n);
            }
            n--;
        }
        cout << set1.size() << endl;
        for (auto i : set1)
            cout << i << ' ';
        cout << endl;
        cout << set2.size() << endl;
        for (auto i : set2)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}
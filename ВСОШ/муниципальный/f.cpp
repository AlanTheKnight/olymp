#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <climits>

#define ll long long

using namespace std;

vector<ll> generate_new(vector<ll> &orig, ll b)
{
    vector<ll> new_vec;
    for (auto i : orig)
        new_vec.push_back(((i > b) ? i : 0));
    return new_vec;
}

ll count_zeros(vector<ll> &nums, ll k)
{
    ll start = 0;
    ll count = 0;
    ll count2 = 0;
    ll minimal = LONG_LONG_MAX - 1;
    for (ll end = 0; end < nums.size(); end++)
    {
        if (nums[end] == 0)
            count += 1;
        count2 = count;
        if (end - start + 1 == k)
        {
            if (nums[start] == 0)
                count -= 1;
            start += 1;
        }
        if (end >= k - 1)
            minimal = min(minimal, count2);
    }
    return minimal;
}

int main()
{
    ll n, k, m;
    cin >> n >> k >> m;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    set<ll> s(a.begin(), a.end());
    vector<ll> ordered;
    ordered.assign(s.rbegin(), s.rend());

    ll win;

    for (auto b : ordered)
    {
        auto nn = generate_new(a, b);
        auto zeros = count_zeros(nn, k);
        if (zeros < m)
            break;
        win = accumulate(nn.begin(), nn.end(), 0) - b;
    }

    cout << win << endl;
}
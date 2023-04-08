#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, count = 1;
    cin >> n;
    vector<ll> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1])
            count++;
    }
    cout << count << endl;
    return 0;
}

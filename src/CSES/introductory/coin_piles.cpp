#define ll long long
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << ((((a + b) % 3 == 0) && (min(a, b) * 2 >= max(a, b))) ? "YES" : "NO") << endl;
    }
}

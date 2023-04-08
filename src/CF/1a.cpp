#include <iostream>
#define ll long long
#define divUp(a, b) ((a + b - 1) / b)
using namespace std;

int main()
{
    ll n, m, a;
    cin >> n >> m >> a;
    cout << divUp(n, a) * divUp(m, a) << endl;
    return 0;
}
#include <iostream>
using namespace std;

#define ceil(x, y) ((x + y - 1) / y)
#define ull unsigned long long


ull solve(ull n) {
    if (n == 1) return 0;
    if (n <= 4) return 1;
    return 1 + ceil(n - 4, 3);
}


int main()
{
    ull n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}


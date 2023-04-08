#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int ans = 2 * N * (N - 1) - 2 * K * (K - 1) * ((N / K) * (N / K));
    cout << ans << endl;
}

#include <iostream>
#include <vector>
using namespace std;


const long long INF = 100000000000;


int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> dp(100000000, INF);


    dp[k] = 1;
    dp[k + 1] = 1;

    int i;
    for (i = k; i < 100000000; i++) {
        dp[i + k] = min(dp[i] + 1, dp[i + k]);
        dp[i + k + 1] = min(dp[i] + 1, dp[i + k + 1]);

        if (i % n == 0 && dp[i] != INF) break;
    }

    cout << dp[i] << endl;
}

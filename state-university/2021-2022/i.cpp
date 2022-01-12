#include <bits/stdc++.h>
using namespace std;

#define ll long long

void handle_positive_sign(vector<ll> &nums, int &n, int start) {
    int i = start;
    while (i < n - 1 && nums[i] >= 0 && nums[i + 1] >= 0) {
        nums[i] = nums[i] + nums[i + 1];
        n--;
    }
}

void process(vector<ll> &nums, int &n) {
    int start = (nums[0] < 0) ? 1 : 0;
    ll next_positive = start + 2;
    while (next_positive > n) {
        next_positive = start + 2;
    }
    ll f_n = (next_positive - 1 >= 0) ? nums[next_positive - 1] : 0;
    ll s_n = (next_positive + 1 < n) ? nums[next_positive + 1] : 0;
    ll nn = min(f_n, s_n);
    nums[next_positive] += nn;
    if (next_positive < 0) {
        
    }

}

void solve() {
    int n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Так как у сложения приоритет выше, то сначала нужно
    // определить места, в которых будет выполняться сложение

    vector<ll> a;

    // ====== Подготовка ======
    int i = 0;
    while (i < n) {
        if (i < n - 1 && nums[i] >= 0 && nums[i + 1] >= 0) {
            // Если подряд встречаются 2+ неотрицательных числа,
            // складываем их вместе
            ll s = 0;
            while (i < n && nums[i] >= 0) {
                s += nums[i];
                i++;
            }
            a.push_back(s);
            continue;
        } else if (i < n && nums[i] < 0) {
            // Пропускаем идущие подряд отрицательные числа
            ll m = nums[i];
            while (i < n && nums[i] < 0) {
                m = min(m, nums[i]);
                i++;
            }
            a.push_back(m);
            continue;
        } else {
            a.push_back(nums[i]);
        }
        i++;
    }

    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // ====== Решение ======
    process(a, n);

    ll m = nums[0];
    for (auto num : nums) {
        if (num < m) {
            m = num;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
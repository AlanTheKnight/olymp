#include <bits/stdc++.h>
using namespace std;

#define FOR(var, start, end) for (size_t var = start; var <= end; var++)
#define FOR_N(var, n) for (size_t var = 0; var < n; var++)
#define FOR_STEP(var, start, end, step) \
    for (size_t var = start; var <= end; var += step)

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> staff(n);
    vector<pair<int, int>> taxi(n);
    vector<int> answer(n + 1);

    FOR_N(i, n) {
        cin >> staff[i].first;
        staff[i].second = i + 1;
    }

    FOR_N(i, n) {
        cin >> taxi[i].first;
        taxi[i].second = i + 1;
    }

    // Сотруднику с наименьшим расстоянием соответствует
    // такси с самым дорогим тарифом

    sort(staff.begin(), staff.end());
    sort(taxi.begin(), taxi.end(), greater<pair<int, int>>());

    FOR_N(i, n) {
        answer[staff[i].second] = taxi[i].second;
        // printf("Сотрудник %d должен ехать на такси №%d\n", staff[i].second,
        //        taxi[i].second);
    }
    FOR(i, 1, n) cout << answer[i] << ' ';
    cout << endl;
}
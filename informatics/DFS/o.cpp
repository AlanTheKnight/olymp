#include <bits/stdc++.h>
using namespace std;

#define FOR(var, start, end) for (size_t var = start; var <= end; var++)
#define FOR_N(var, n) for (size_t var = 0; var < n; var++)
#define FOR_STEP(var, start, end, step) \
    for (size_t var = start; var <= end; var += step)

struct TrainData {
    int start;
    int end;
    int start_time;
    int speed;
};

vector<TrainData> trains;

int main() {
    int n;
    cin >> n;
    trains.resize(n);

    FOR_N(i, n) {
        cin >> trains[i].start >> trains[i].end >> trains[i].start_time >>
            trains[i].speed;
    }
    
}

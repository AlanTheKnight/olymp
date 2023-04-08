#include <bits/stdc++.h>
using namespace std;

regex DATE_PATTERN("(0[1-9]|1[0-9]|2[0-9]|30|31)-(0[1-9]|1[0-2])-(201[3-5])");
int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

map<string, int> result;

void proceed(string &s, int index) {
    string n = s.substr(index, 10);
    smatch m;
    regex_search(n, m, DATE_PATTERN);
    if (m.size() == 4) {
        int month = stoi(m[2]);
        int day = stoi(m[1]);

        // Количество дней правильное
        if (day <= months[month - 1]) {
            result[n]++;
        }
    }
}

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.length() - 9; i++) {
        proceed(s, i);
    }

    pair<string, int> maximal = make_pair("", 0);
    for (auto i : result) {
        if (i.second > maximal.second) {
            maximal = i;
        }
    }

    cout << maximal.first << endl;
}

#include <bits/stdc++.h>
using namespace std;

struct el {
    int id;
    int32_t reliability;
};

bool custom_sort(pair<string, el> const &a, pair<string, el> const &b) {
    if (a.second.reliability == b.second.reliability) {
        return a.second.id < b.second.id;
    }
    return a.second.reliability > b.second.reliability;
}

vector<pair<string, el>> db_sorted;
map<string, el> db;
int last_id = 0;

void DB_delete(string code) {
    if (db.find(code) == db.end()) {
        cout << "BAD REQUEST" << endl;
        return;
    }
    cout << "OK " << db[code].id << " " << db[code].reliability << endl;
    db.erase(code);
}

void DB_add(string code) {
    if (db.find(code) != db.end()) {
        cout << "EXISTS " << db[code].id << " " << db[code].reliability << endl;
        return;
    }
    db[code] = {last_id, 0};
    lower_bound(db_sorted.begin(), db_sorted.end(), make_pair(code, db[code]),
                custom_sort)
        ->second = db[code];
    cout << "CREATED " << last_id++ << " " << 0 << endl;
}

void DB_CHANGE(string code, int32_t reliability) {
    if (db.find(code) == db.end()) {
        cout << "BAD REQUEST" << endl;
        return;
    }
    db[code].reliability = reliability;
    lower_bound(db_sorted.begin(), db_sorted.end(), make_pair(code, db[code]),
                custom_sort)
        ->second = db[code];
    cout << "OK " << db[code].id << " " << db[code].reliability << endl;
}

void DB_FIND(int n) {
    if (db.size() == 0) {
        cout << "EMPTY" << endl;
        return;
    }

    vector<pair<string, el>> v(db.begin(), db.end());
    sort(v.begin(), v.end(), &custom_sort);
    int index = min(n, (int)(v.size() - 1));
    cout << "OK " << v[index].first << " " << v[index].second.id << " "
         << v[index].second.reliability << endl;
}

int main() {
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        if (s == "DELETE") {
            string code;
            cin >> code;
            DB_delete(code);
        } else if (s == "ISSUE") {
            string code;
            cin >> code;
            DB_add(code);
        } else if (s == "RELIABILITY") {
            string code;
            int32_t reliability;
            cin >> code >> reliability;
            DB_CHANGE(code, reliability);
        } else if (s == "FIND") {
            int n;
            cin >> n;
            DB_FIND(n);
        }
    }
}
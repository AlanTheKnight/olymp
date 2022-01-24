#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int, int> m;
    string op;
    int n, num, count = 0;
    cin >> n;
    while (n--) {
        cin >> op >> num;
        if (op == "insert") {
            m[num]++;
            count++;
        } else {
            if (m.find(num) != m.end()) {
                if (m[num] == 1) {
                    m.erase(num);
                } else {
                    m[num]--;
                }
                count--;
            }
        }

        if (count < 2)
            cout << "neither" << endl;
        else if (m.size() == 1)
            cout << "homo" << endl;
        else if (count == m.size())
            cout << "hetero" << endl;
        else
            cout << "both" << endl;
    }
}

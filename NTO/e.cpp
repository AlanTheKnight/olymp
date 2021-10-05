#include <vector>
#include <iostream>
using namespace std;

int START_P, END_P, VALUE;
bool STOP_LOOP;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int p, t;
    cin >> p >> t;
    a.insert(a.begin() + p, t);

    for (auto i : a) cout << i << ' ';
    cout << endl;

    START_P = p;
    END_P = p;
    VALUE = t;
    STOP_LOOP = false;

    while (!STOP_LOOP)
    {
        int nextPos = ((END_P + 1) < (a.size())) ? END_P + 1 : 0;
        int prevPos = ((START_P - 1) < 0) ? (a.size() - 1) : START_P - 1;
        int next = a[nextPos], prev = a[prevPos];

        cout << "CUR: " << next << ' ' << VALUE << ' ' << prev << ' ';
        cout << "START = " << START_P << ' ' << "END = " << END_P << endl;

        if (next == prev && VALUE == next)
        {
            // cout << "EXPAND BOTH" << endl;
            START_P = prevPos;
            END_P = nextPos;
            VALUE += 2;
        }
        else if (next == VALUE)
        {
            // cout << "EXPAND END" << endl;
            END_P = nextPos;
            VALUE++;
        }
        else if (prev == VALUE)
        {
            // cout << "EXPAND START" << endl;
            START_P = prevPos;
            VALUE++;
        }
        else
        {
            STOP_LOOP = true;
        }
    }

    if (VALUE == t + a.size() - 1)
    {
        cout << 1 << endl;
    }
    else if (VALUE == t && END_P == START_P)
    {
        cout << a.size() << endl;
    }
    else
    {
        cout << max(START_P, END_P) - min(START_P, END_P) << endl;
    }
    return 0;
}

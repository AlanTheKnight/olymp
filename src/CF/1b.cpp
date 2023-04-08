#include <iostream>
#include <string>
#include <cmath>
#define ll long long
#define divUp(a, b) ((a + b - 1) / b)
using namespace std;

string toExcel(string s)
{
    string res = "";
    // Convert x to number with base 26
    ll base = 26;
    ll y = stoi(s);
    while (y > 0)
    {
        res = char(y % base - 1 + 'A') + res;
        y /= base;
    }
    return res;
}

string toNumber(string s)
{
    // Convert number with base 26 to decimal
    ll base = 26;
    ll y = 0;
    for (int i = 0; i < s.size(); i++)
    {
        y += (s[i] - 'A' + 1) * pow(base, s.size() - 1 - i);
    }
    return to_string(y);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s, res;
        cin >> s;
        if (s[0] == 'R')
        {
            int c = s.find('C');
            res = toExcel(s.substr(c + 1, s.length() - c - 1)) + s.substr(1, c - 1);
        }
        else
        {
            int c = 0;
            while (s[c] < '0' || s[c] > '9')
                c++;
            res = 'R' + s.substr(c, s.length() - c) + 'C' + toNumber(s.substr(0, c)) ;
        }
        cout << res << endl;
    }
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    unsigned long long s, e;
    cin >> s >> e;
    if (s == 1)
    {
        cout << 1 << endl;
    }
    else if (s == e)
    {
        cout << -1 << endl;
    }
    else
    {
        unsigned long long i = (s - 1) / (e - s);
        unsigned long long delta = s * (i + 1) - (e * i + 1);
        if (delta != 0) i++;
        cout << s * i << endl;  
    }
    return 0;
}

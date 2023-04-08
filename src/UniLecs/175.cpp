#include <unordered_map>
#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;
    int arr[size], k;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cin >> k;

    unordered_map<int, int> m;
    int count = 0, s = 0;
    m[0] = 1;
    for (int i = 0; i < size; i++)
    {
        s += arr[i];
        if (m.find(s - k) != m.end())
            count += m[s - k];
        m[s] = (m.find(s) != m.end()) ? m[s]+1 : 1;
    }
    cout << count << endl;

    return 0;
}

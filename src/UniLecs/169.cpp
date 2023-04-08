#include <iostream>
#define LL long long
using namespace std;


/*
pref- массив произведений префиксов
suff - массив произведений суффиксов
A - исходный массив

Если мы сместим массивы pref и suff на 1,
то для каждого элемента найдем произведение
всех элементов до i-ого элемента и после.
И сможем найти значение в конечном массиве.

Сложность: O(n)

+------+----+----+----+----+----+----+
|    A |    |  1 |  2 |  3 |  4 |    |
+------+----+----+----+----+----+----+
| pref |    |  1 |  1 |  2 |  6 | 24 |
+------+----+----+----+----+----+----+
| suff | 24 | 24 | 12 |  4 |  1 |    |
+------+----+----+----+----+----+----+
| Итог |    | 24 | 12 |  8 |  6 |    |
+------+----+----+----+----+----+----+
*/


int main(int argc, char const *argv[])
{
    int length; cin >> length;
    LL A[length], pref[length+1], suff[length+1];
    pref[0] = 1; suff[length] = 1;

    for (int i = 0; i < length; i++) cin >> A[i];

    for (int i = 1; i <= length; i++) pref[i] = pref[i-1] * A[i-1];
    for (int i = length-1; i >= 0; i--) suff[i] = suff[i+1] * A[i];
        
    for (int i = 0; i < length; i++) A[i] = pref[i] * suff[i+1];

    for (int i = 0; i < length; i++) cout << A[i] << ' ';
    cout << endl;
}

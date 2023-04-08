#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a * (b / 2) + ((b % 2 != 0 && a > 1) ? a / 2 : 0) << endl;
}
#include <bits/stdc++.h>

using namespace std;


string convertToDigits(string &str) {
    string output;
    int count[26] = {0}, digits[10] = {0};
    for (char c : str) count[c - 'a']++;

    digits[0] = count['z' - 'a'];
    digits[2] = count['w' - 'a'];
    digits[4] = count['u' - 'a'];
    digits[6] = count['x' - 'a'];
    digits[8] = count['g' - 'a'];
    digits[1] = count['o' - 'a'] - digits[0] - digits[2] - digits[4];
    digits[3] = count['h' - 'a'] - digits[8];
    digits[5] = count['f' - 'a'] - digits[4];
    digits[7] = count['s' - 'a'] - digits[6];
    digits[9] = count['i' - 'a'] - digits[6] - digits[5] - digits[8];

    for (int i = 0; i < 10; i++) output.append(digits[i], '0' + i);
    return output;
}

int main() {
    string str;
    getline(cin, str);
    cout << convertToDigits(str) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const pair<int, const char*> table[13] = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
    {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
    {5, "V"},    {4, "IV"},   {1, "I"},
};

class Solution {
 public:
  string intToRoman(int num) {
    string res = "";
    int i = 0;

    while (num) {
      for (int j = 0; j < (num / table[i].first); j++) res += table[i].second;
      num %= table[i].first;
      i++;
    }

    return res;
  }
};


int main() {
    Solution s;
    cout << s.intToRoman(1994) << endl;
}

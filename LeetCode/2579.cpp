// 2579. Count Total Number of Colored Cells

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long coloredCells(int n) {
    long long ans = 1;
    for (int i = 1; i < n; i++) {
      ans += (i - 1) * 4 + 4;
    }
    return ans;
  }
};

int main() {
  Solution s;
  cout << s.coloredCells(3) << endl;
  return 0;
}

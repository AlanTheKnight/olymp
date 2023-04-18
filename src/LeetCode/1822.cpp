#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int arraySign(vector<int>& nums) {
    int negativeCount = 0;
    for (auto i : nums) {
      if (i < 0) negativeCount++;
      if (i == 0) return 0;
    }
    return (negativeCount % 2 == 0) ? 1 : -1;
  }
};

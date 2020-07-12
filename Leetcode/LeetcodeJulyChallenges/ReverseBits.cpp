class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    int j = 31, i = 0;
    uint32_t ans = 0;
    bool bi, bj;
    while (j > i) {
      bj = ((n >> j) & 1);
      bi = ((n >> i) & 1);
      ans = (ans | (bi << j));
      ans = (ans | (bj << i));

      j--;
      i++;
    }
    return ans;
  }
};
// 二分
class Solution{
  public:
    int getMissingNumber(vector<int>& nums) {
      if (nums.empty()) {
        return 0;
      }
      int l = 0, r = nums.size() -1;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] != mid) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      if (nums[r] == r) {
        return r + 1;
      } else {
        return r;
      }
    }
}
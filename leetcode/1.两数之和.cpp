class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int>res;
      map<int,int>hash;
      for (int i = 0; i < nums.size(); i ++) {
        hash[nums[i]] = i;
      }
      for (int i = 0;i<nums.size();i++) {
          int k = target - nums[i];
          if ( hash[k] != i) {
              res.push_back(i);
              res.push_back(hash[k]);
              return res;
          }
      }
      return vector<int>{};
    }
};
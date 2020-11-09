// 双指针解法
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int l = 0, r= array.size() - 1;
        while (l < r ) {
            while (l < r && array[l] % 2 == 1) l ++;
            while (l < r && array[r] % 2 == 0) r --;
            if (l < r) swap(array[l], array[r]);
        }
    }
};
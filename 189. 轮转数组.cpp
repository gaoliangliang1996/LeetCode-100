// 图解参考: https://juejin.cn/post/7231385783181361213
// 方法一：数组拷贝方式
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> bak(nums);
        int length = nums.size();

        for (int i = 0; i < length; ++i) {
            nums[(i + k) % length] = bak[i];
        }
    }
};

// 方法二：反转数组
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return;
        
        k = k % nums.size();  
        if (k == 0)
            return;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

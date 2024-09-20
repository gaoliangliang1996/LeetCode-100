// 参考图解: https://cloud.tencent.com/developer/article/2284082
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int pre = 0;

        for (int i = 0; i < nums.size(); ++i) {
            pre = max(nums[i], nums[i] + pre);
            if (pre > result)
                result = pre;
        }

        return result;
    }
};

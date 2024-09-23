// 图解: https://cloud.tencent.com/developer/article/2284535
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> left_product(length, 1), right_product(length, 1);
        vector<int> result(length);

        // 计算每个元素  左边元素的积，存入left_product
        int left = 1;
        for (int i = 0; i < length; ++i) {
            left_product[i] = left;
            left = left * nums[i];
        }

        // 计算每个元素  右边元素的积，存入right_product
        int right = 1;
        for (int j = length - 1; j >= 0; --j) {
            right_product[j] = right;
            right = right * nums[j];
        }

        // 最终的结果为 左边元素积 * 右边元素积
        for (int k = 0; k < length; ++k)
            result[k] = left_product[k] * right_product[k];

        return result;
    }
};

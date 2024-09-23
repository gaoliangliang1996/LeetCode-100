图解: https://cloud.tencent.com/developer/article/1550069
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int result = 0;
        int length = nums.size();

        for (int i = 0; i < length; ++i) {
            while (nums[i] > 0 && nums[i] <= length && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int j = 0; j < length; ++j) {
            if (nums[j] != (j + 1)){
                result = j + 1;
                return result;
            }
        }

        result = length + 1;
        return result;
    }
};

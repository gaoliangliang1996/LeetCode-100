class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int result = 0;
        int current_cum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            current_cum += nums[i];

            if (mp.find(current_cum - k) != mp.end()) {
                result += mp[current_cum - k];
            }

            mp[current_cum]++;
        }

        return result;
    }
};

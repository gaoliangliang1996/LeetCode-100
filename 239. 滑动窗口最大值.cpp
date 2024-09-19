class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < nums.size(); ++i) {
            // 移除队列中索引值已经过期的元素（不在当前窗口内）
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // 移除队列中所有小于当前元素的索引值  
            // 因为它们不可能成为最大值
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // 添加当前元素的索引到队列  
            dq.push_back(i);

            // 当窗口大小达到 k 时，添加当前窗口的最大值到结果中  
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

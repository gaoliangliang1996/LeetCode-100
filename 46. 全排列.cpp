// https://www.hello-algo.com/chapter_backtracking/permutations_problem/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> state;

        vector<bool> selected(nums.size(), false);
        backtrack(state, nums, selected, res);
        return res;
    }

    void backtrack(vector<int> &state, vector<int>& nums, vector<bool>& selected, vector<vector<int>>& res) {
        if (state.size() == nums.size()) {
            res.push_back(state);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (!selected[i]) {
                state.push_back(num);
                selected[i] = true;
                backtrack(state, nums, selected, res);
                state.pop_back();
                selected[i] = false;
            }
        }
    }
};

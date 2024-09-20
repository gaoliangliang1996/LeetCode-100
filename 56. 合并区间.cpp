参考图解: https://developer.aliyun.com/article/1207877
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.empty()) {
            return {};
        }

        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());

        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            vector<int>& current = intervals[i];
            vector<int>& lastMerged = result.back();
            if (current[0] <= lastMerged[1]) {
                lastMerged[1] = max(current[1], lastMerged[1]);
            } else {
                result.push_back(current);
            }
        }

        return result;
    }
};

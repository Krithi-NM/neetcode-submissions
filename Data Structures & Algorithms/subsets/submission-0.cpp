class Solution {
public:
    void returnsubsets(vector<int>& nums, vector<int>& ans, int i,
                       vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        returnsubsets(nums, ans, i + 1, res);
        ans.pop_back();
        returnsubsets(nums, ans, i + 1, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        returnsubsets(nums, ans, 0, res);
        return res;
    }
};
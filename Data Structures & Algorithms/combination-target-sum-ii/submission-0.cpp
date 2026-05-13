class Solution {
public:
    void solve(vector<int>& nums, vector<int>& temp, vector<vector<int>>& res, int idx, int target) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            // Skip duplicates
            if (i > idx && nums[i] == nums[i - 1]) continue;

            // Prune
            if (nums[i] > target) break;

            temp.push_back(nums[i]);
            solve(nums, temp, res, i + 1, target - nums[i]); // move forward
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;

        sort(nums.begin(), nums.end());  

        solve(nums, temp, res, 0, target);

        return res;
    }
};
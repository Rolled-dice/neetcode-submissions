class Solution {
public:
    void solve(vector<int> &nums,vector<int>temp,vector<vector<int>> &res,int idx,int target){
         if (nums.size()==idx || target<0) return;
         if(target==0){
            res.push_back(temp);
            return;
         }
         temp.push_back(nums[idx]);
         solve(nums,temp,res,idx,target-nums[idx]);
         temp.pop_back();
         solve(nums,temp,res,idx+1,target);
         return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        solve(nums,temp,res,0,target);

        return res;
    }
};

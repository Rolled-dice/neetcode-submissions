class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&res,int idx){
         if(nums.size()==idx){
            res.push_back(nums);
            return;
         }
         for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            solve(nums,res,idx+1);
            swap(nums[idx],nums[i]);
         }
         return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        solve(nums,res,0);
        return res;
    }
};

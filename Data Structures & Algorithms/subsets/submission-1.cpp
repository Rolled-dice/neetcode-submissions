class Solution {
public:
   void solve(vector<int>& nums,int idx,vector<vector<int>>& res,vector<int> &temp){
      if(nums.size()==idx){
         res.push_back(temp);
         return;
      }
         temp.push_back(nums[idx]);
         solve(nums,idx+1,res,temp);
         temp.pop_back();
         solve(nums,idx+1,res,temp);
         return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,0,ans,temp);

        return ans;
    }
};

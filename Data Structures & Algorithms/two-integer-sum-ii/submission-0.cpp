class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         sort(begin(nums),end(nums));
         int i=0,j=nums.size()-1;
         while(i<j){
            int s=nums[i]+nums[j];
            if (s==target)return {i+1,j+1};
            else if(s>target)j--;
            else i++;
         }
         return {-1,-1};
    }
};

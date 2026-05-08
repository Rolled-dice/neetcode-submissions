class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, zc = 0, zind = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zc++;
                zind = i;
            } else {
                prod *= nums[i];
            }
        }

        vector<int> ans(nums.size(), 0);

        // Case 1: More than one zero → all products are zero
        if (zc > 1) return ans;

        // Case 2: Exactly one zero → only one non-zero result
        if (zc == 1) {
            ans[zind] = prod;
            return ans;
        }

        // Case 3: No zero → normal division
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = prod / nums[i];
        }

        return ans;
    }
};

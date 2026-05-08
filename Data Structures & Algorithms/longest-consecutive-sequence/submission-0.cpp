class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int l=0;
        for(auto &it:nums){

            if (st.find(it-1)==st.end()){
                int n=it;
                int streak=1;
                while(st.find(n+1)!=st.end()){
                     n++;
                     streak++;
                }
                 l=max(l,streak);
            }
        }
        return l;
    }

};

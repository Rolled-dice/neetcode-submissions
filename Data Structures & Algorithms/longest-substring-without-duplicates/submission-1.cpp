class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int j=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            while(mp[s[i]] > 0){
                mp[s[j++]]--;
                
            }
            ans=max(ans,i-j+1);
            mp[s[i]]++;         
        }
        return ans;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int maxf=0;
        int r=0;
        int res=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            maxf=max(maxf,mp[s[i]]);
            while((i-r+1)-maxf>k){
                mp[s[r++]]--;
            }
            res=max(res,i-r+1);

        }
        return res;
    }
};

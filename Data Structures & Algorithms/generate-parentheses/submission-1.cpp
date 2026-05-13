class Solution {
public:
    void solve(int o,int c,int n,vector<string> &res,string &temp){
         if(o==n && c==n){
             res.push_back(temp);
             return;
         }
         if(o<n){
            temp+="(";
            solve(o+1,c,n,res,temp);
            temp.pop_back();
         }
        if(c<o){
             temp+=")";
             solve(o,c+1,n,res,temp);
             temp.pop_back();
         }
         return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        solve(0,0,n,ans,temp);
        return ans;
    }
};

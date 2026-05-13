class Solution {
public:
    bool ispal(string s,int i,int j){
        while(i<j){
             if(s[i]!=s[j]) return false;
             i++;
             j--;
        }
        return true;
    }
    void solve(int idx,string &s,vector<vector<string>>&ans,vector<string>&temp){
         if(idx>=s.size()){
            ans.push_back(temp);
            return;
         }
         for(int j=idx;j<s.size();j++){
             if(ispal(s,idx,j)){
                temp.push_back(s.substr(idx,j-idx+1));
                solve(j+1,s,ans,temp);
                temp.pop_back();
             }
         }
    }
    vector<vector<string>> partition(string s) {
       vector<vector<string>>ans;
       vector<string>temp;
       solve(0,s,ans,temp);
       return ans;    
    }
};


// we need to check the every substring is palingdrome.
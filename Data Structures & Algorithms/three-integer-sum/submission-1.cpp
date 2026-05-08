class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>>st;

        vector<int> rr = nums;
        sort(begin(rr),end(rr));
        for(int i=0;i< (int)rr.size()-2;i++){
             int j=i+1;
             int k=rr.size()-1;
             while(j<k){
                int s=rr[i]+rr[j]+rr[k];
                if(s==0){
                    st.insert({rr[i],rr[j],rr[k]});
                    j++; k--;
                }
                else if(s>0){
                    k--;
                }else j++;
             }
        }
        for(auto it:st){
             res.push_back(it);
        }
        return res;
    }
};
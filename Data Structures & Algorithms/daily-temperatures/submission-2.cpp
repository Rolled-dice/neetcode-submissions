class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> temp=temperatures;
        vector<int>nge(temp.size(),0);
        stack<int>st;
        for(int i=temp.size()-1;i>=0;i--){
             while(!st.empty() && temp[st.top()]<=temp[i]){
                st.pop();
             }
             nge[i]=st.empty()?0:st.top()-i;
             st.push(i);
        }
        return nge;
    }
};

class Solution {
public:
    int rows,cols;
    bool solve (int idx,int i,int j,vector<vector<char>>& board,string word) {
        if(idx==word.size()){
            return true;
        }  
        if(i<0|| j<0 || i>=rows|| j>=cols || board[i][j]!=word[idx] || board[i][j]=='#'){
        return false;
        }
        board[i][j]='#';
        bool res=solve(idx+1,i+1,j,board,word)||solve(idx+1,i-1,j,board,word)||solve(idx+1,i,j+1,board,word)||
        solve(idx+1,i,j-1,board,word);
        board[i][j]=word[idx];
        return res;
    } 
    bool exist(vector<vector<char>>& board, string word) {
        rows=board.size();
        cols=board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(solve(0,i,j,board,word)){
                    return true;
                }
            }
        }
        return false;   
    }
};

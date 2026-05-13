class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time =0;
        vector<int>freq(26,0);
        priority_queue<int>mx;
        for(int i=0;i<tasks.size();i++){
             freq[tasks[i]-'A']++;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]>0)mx.push(freq[i]);
        }
        queue<pair<int,int>>q;
        while(!mx.empty()||!q.empty()){
             time++;
             if(mx.empty()){
                 time=q.front().second;
                
             }else{
                int cnt=mx.top()-1;
                mx.pop();
                if(cnt>0){
                     q.push({cnt,time+n});
                }
             }
             if(!q.empty() && q.front().second==time){
                 mx.push(q.front().first);
                 q.pop();
             }
        }
         return time;
    }
};

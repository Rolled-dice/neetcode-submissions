class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int r) {
        int l=1;
        int h=*max_element(piles.begin(),piles.end());
        while(l<=h){
            int m= l+(h-l)/2;
            int time=0,f=0;
            for(int i=0;i<piles.size();i++){
                 time+=(piles[i]+m-1)/m;
                 if(time>r){
                    f=1;
                    break;
                 }
            }
            if(f)l=m+1;
            else h=m-1; 
        }
        return l;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        priority_queue<pair<int, int>>pq;
        int currm=0;
        for(int i=0;i<k;i++){
         pq.push({nums[i], i});
        }
        res.push_back(pq.top().first);
        int j=0;
        for(int i=k;i<nums.size();i++){
            j++;
            pq.push({nums[i], i});
            while(pq.top().second < j) pq.pop();
            res.push_back(pq.top().first);
        }
         return res;
    }
};

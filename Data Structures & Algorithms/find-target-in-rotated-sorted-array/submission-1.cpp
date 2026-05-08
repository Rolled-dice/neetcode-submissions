class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l =0;
        int h =nums.size()-1;
        while(l<=h){
            int mid=(l+h)>>1;
            if(nums[mid]==target) return mid;
            else if (nums[l]<=nums[mid]){   // left part...
                    if(nums[mid]>target && nums[l]<=target) h=mid-1;
                    else l=mid+1;
            }else {
                  if(nums[mid]<target && nums[h]>=target) l=mid+1;
                  else h=mid-1;
            }
        }
        return -1;
    }
};

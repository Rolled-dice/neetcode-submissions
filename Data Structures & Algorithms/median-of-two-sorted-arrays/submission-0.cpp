class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int n1=nums1.size(),n2=nums2.size();
        
          int i=0,j=0;
        
          int n =n1+n2;
          int e2=n/2;
          int e1=e2-1;
          int cnt=0;
           int i1=-1,i2=-1;
          while(i<n1 && j<n2){
              
              if(nums1[i]<nums2[j]){
                  if(cnt ==e1) i1=nums1[i]; 
                  if(cnt ==e2)  i2=nums1[i];  
                  cnt++;
                  i++;
              }else{
                  if(cnt ==e1) i1=nums2[j]; 
                  if(cnt ==e2) i2=nums2[j];  
                  cnt++;
                   j++;
              }
          }
        
        while(i<n1) {
                  if(cnt ==e1) i1=nums1[i]; 
                  if(cnt ==e2)  i2=nums1[i];  
                 cnt++;
                  i++;
              
        }
        while(j<n2) {
                  if(cnt ==e1)  i1=nums2[j]; 
                  if(cnt ==e2)  i2=nums2[j];  
                  cnt++;
                  j++;
              
        }
        
        if(n&1) return (double)i2;
        
        return (i1+i2)/2.0;
        
    }
}; // merge help here in this wee ca n suse the cocept og merge sort..
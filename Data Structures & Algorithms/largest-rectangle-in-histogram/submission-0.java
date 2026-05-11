class Solution {
    public int largestRectangleArea(int[] heights) {
        int n=heights.length;
        int []nge=new int[n];
        int []pge=new int[n];
        // Stack<int> st=new Stack<>();
        Stack<Integer> st = new Stack<>();
        for(int i=0;i<n;i++){
             while(!st.empty()  && heights[i]<=heights[st.peek()]) st.pop();
             pge[i]=st.empty()?-1:st.peek();
             st.push(i);
        }
         st.clear();
        for(int i=n-1;i>=0;i--){
             while(!st.empty()  && heights[i]<=heights[st.peek()]) st.pop();
             nge[i]=st.empty()?n:st.peek();
             st.push(i);
        }
        int res=0;
        for(int i=0;i<n;i++){
           res =Math.max(res ,heights[i]*(nge[i]-pge[i]-1));
        }
        return res;
    }
}

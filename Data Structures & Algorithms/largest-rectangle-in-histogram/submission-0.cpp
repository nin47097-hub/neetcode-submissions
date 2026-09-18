class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int  n = heights.size();
        int max_area =0;
        for(int i =0; i<= n;i++)
        {
            int current_height = (i == n) ? 0 : heights[i];
            while(!st.empty() && current_height<=heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                int w  = st.empty()?i:i-st.top()-1;
                max_area = max(max_area, w*h);



            }
            st.push(i);


        }
        return max_area;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>ls(n);
        vector<int>rs(n);
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty())ls[i] = 0;
            else ls[i] = st.top() + 1;
            st.push(i);
        }
        int ans = 0;
        while(!st.empty())st.pop();
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            int x;
            if(st.empty())x = n-1;
            else x = st.top() - 1;
            st.push(i);
            ans = max(ans, (abs(ls[i] - x) + 1) * heights[i]);
        }
        return ans;
    }
};
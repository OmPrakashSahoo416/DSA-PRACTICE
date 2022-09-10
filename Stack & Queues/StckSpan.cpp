class StockSpanner {
    stack<int>st;
    vector<int>v;
    int ind = -1;
public:
   
    int next(int price) {
        int count = 1;
        int k = ind;
        ind++;
        while(!st.empty() && st.top() <= price && k >= 0){
            count += v[k];
            k -= v[k];
            st.pop();
        }
        v.push_back(count);
        st.push(price);
        return v[ind];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
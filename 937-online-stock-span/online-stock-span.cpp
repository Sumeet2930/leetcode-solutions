class StockSpanner {
private: 
    stack<pair<int,int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cur_span = 1;
        while (!st.empty() && st.top().first <= price){
            cur_span += st.top().second;
            st.pop();

        }

        st.push({price, cur_span});

        return cur_span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
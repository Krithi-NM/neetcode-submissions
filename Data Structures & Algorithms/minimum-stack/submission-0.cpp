class MinStack {
private:
    stack<long long>st;
    long long minval;

public:
    MinStack() {
        minval = LLONG_MAX;
    }
    
    void push(int val) {
        if (st.empty()){
            st.push(val);
            minval=val;
        }else if (val>=minval){
            st.push(val);
        }else{
            st.push(2LL*val-minval);
            minval=val;
        }
    }
    
    void pop() {
        if (st.top()<minval){
            minval=2LL*minval-st.top();
        }
        st.pop();
    }
    
    int top() {
        if (st.top()<minval){
            return minval;
        }
        return st.top();
    }
    
    int getMin() {
        return minval;
    }
};
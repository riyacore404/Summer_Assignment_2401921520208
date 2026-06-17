#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack < long long > st;
    long long mini;
public:
    MinStack() {
        while (!st.empty()) st.pop();
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        }
        else if (val < mini) {
            st.push(2LL*val - mini);
            mini = val;
        }
        else st.push(val);
    }
    
    void pop() {
        long long el = st.top();
        st.pop();
        if (el < mini) mini = 2LL*mini - el;
    }
    
    int top() {
        long long el = st.top();
        if (el < mini) return mini;

        return el;
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
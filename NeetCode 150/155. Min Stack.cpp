class MinStack {
public:
    MinStack() { }

    void push(int val) {
        int mn = stk.size() ? stk.top().second : val;
        mn = min(mn, val);
        stk.push({val, mn});
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top().first;
    }

    int getMin() {
        return stk.top().second;
    }
private:
    stack<pair<int,int>> stk;
};

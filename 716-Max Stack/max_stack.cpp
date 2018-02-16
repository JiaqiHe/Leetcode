class MaxStack {
private:
    list<int> stk;
    map<int, list<list<int>::iterator>> dict;
    // here we use map because we want to use "rbegin" to retrive the max value
    // amazingly, map would sort the elements if you use iterator to traverse them!!!!
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        stk.push_back(x);
        dict[x].push_back(--stk.end());
        //O(1)
    }
    
    int pop() {
        int last = stk.back();
        stk.pop_back();
        dict[last].pop_back();//O(log n) here because map[] is O(log n) time
        if(dict[last].empty()) dict.erase(last);
        return last;
        //O(log n)
    }
    
    int top() {
        return stk.back();
        //O(1)
    }
    
    int peekMax() {
        return dict.rbegin()->first;
        //O(1)
    }
    
    int popMax() {
        int max_val = dict.rbegin()->first;
        list<int>::iterator position = dict[max_val].back();
        stk.erase(position);
        dict[max_val].pop_back();
        if(dict[max_val].empty()) dict.erase(max_val);
        return max_val;
        //O(log n)
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */

#include<stack>
#include<algorithm>
class MinStack {
private:
    std::stack<int>minstack;
    std::stack<int>stack_m;
    
public:
    MinStack() {
   

        
    }
    
    void push(int val) {
        stack_m.push(val);
        if(minstack.empty()){
            minstack.push(val);
        }
        else{
            int min_val = std::min(val,minstack.top());
            minstack.push(min_val);
        }
        
    }
    
    void pop() {
        stack_m.pop();
        minstack.pop();

        
    }
    
    int top() {
        return stack_m.top();
        
    }
    
    int getMin() {
        return minstack.top();
        
    }
};

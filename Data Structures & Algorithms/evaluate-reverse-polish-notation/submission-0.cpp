#include<stack>
#include<algorithm>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        std::stack<int>my_stack;
        for(std::string i:tokens){
            if(i=="+"){
                int a = my_stack.top();
                my_stack.pop();
                int b = my_stack.top();
                my_stack.pop();
                my_stack.push(a+b);
            }
            else if(i=="-"){
                int a = my_stack.top();
                my_stack.pop();
                int b = my_stack.top();
                my_stack.pop();
                my_stack.push(b-a);

            }
            else if(i =="*"){
                int a = my_stack.top();
                my_stack.pop();
                int b = my_stack.top();
                my_stack.pop();
                my_stack.push(a*b);

            }
            else if(i == "/"){
                int a = my_stack.top();
                my_stack.pop();
                int b = my_stack.top();
                my_stack.pop();
                my_stack.push(b/a);

            }
            else{
                my_stack.push(std::stoi (i));
            }
        }
        return my_stack.top();

        
    }
};

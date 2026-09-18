#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char>mu_stack;
        std::unordered_map<char,char>pairs{
            {')','('},
            {']','['},
            {'}','{'}
        };

        for(char i : s){
            if (i=='('||i=='['||i=='{'){
                mu_stack.push(i);
            }
            else{
               
                if(mu_stack.empty()||mu_stack.top()!=pairs[i]){
                    return false;
                }
            
                mu_stack.pop();
                

    
            }
        }
        return mu_stack.empty();

        
    }
};

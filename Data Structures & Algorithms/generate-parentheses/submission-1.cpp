class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int left =0;
        int right = 0;
        vector<string>output;
        vector<char>temp; 

        dfs(0,0,n,temp, output);
        return output;
    }

private:  
    void dfs(int left, int right, int n, vector<char>& temp, vector<string>& output){


        if(left== right && temp.size()== 2*n){
            string s(temp.begin(), temp.end());
            
            output.push_back(s);
            return;
        }
        if(left<n){
            temp.push_back('(');
            dfs(left+1, right, n, temp, output);
            temp.pop_back();
        }
        if(right<left){
            temp.push_back(')');
            dfs(left, right+1, n, temp, output);
            temp.pop_back();
        }
    }
};

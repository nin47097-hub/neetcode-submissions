class Solution {
public:
    int numDistinct(string s, string t) {
        int cols = s.size();
        int rows = t.size();
        std::vector<std::vector<int>> memo(rows, std::vector<int>(cols, -1));
        if(t.size()> s.size()){
            return 0;
        }   
        return dfs(0,0,memo,s,t);
    }
private:  
    int dfs(int index, int j, vector<vector<int>>& memo, string & s, string & t ){
        if(index >=t.size()){
            return 1;
        }
        if(j>= s.size()){
            return 0;
        }
        if(memo[index][j]!=-1){
            return memo[index][j];
        }
        int res = dfs(index, j+1,memo,s,t );

        if(s[j] == t[index]){
            res += dfs(index+1, j+1, memo,s,t);
        }
        memo[index][j] = res;
        return memo[index][j];



    }
};

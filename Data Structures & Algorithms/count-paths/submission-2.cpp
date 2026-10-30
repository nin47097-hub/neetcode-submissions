class Solution {
public:
    int uniquePaths(int m, int n) {

        if(n<=0|| m<=0){
            return 0;
        }

        vector<vector<int>> p(m, vector<int>(n,0));
        p[0][0]=1;


        for(int i =1;i<m;i++){
            p[i][0]+=1;

        }
        for(int j =1; j<n;j++){
            p[0][j] +=1;
        }


        for(int i =1; i< m;i++){
            for(int j=1; j<n; j++){
                (p[i][j] += p[i-1][j] + p[i][j-1]);

            }
        }
        return p[m-1][n-1];
        
    }
};

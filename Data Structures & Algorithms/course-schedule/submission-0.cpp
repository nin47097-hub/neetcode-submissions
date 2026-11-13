class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int preq = prerequisites[i][1];
            adj[course].push_back(preq);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                
                if (!canComplete(i, adj, state)) {
                    return false;
                }
            }
        }

        return true; 
    }

private:
    
    bool canComplete(int course, unordered_map<int, vector<int>>& adj, vector<int>& state) {
        if (state[course] == 1) {
            return false; 
        }
        if (state[course] == 2) {
            return true;  
        }

        state[course] = 1; 

        for (int preq : adj[course]) {
            if (!canComplete(preq, adj, state)) {
                return false; 
            }
        }

        state[course] = 2; 
        return true;       
    }
};


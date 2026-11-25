class CountSquares {
private:
    vector<pair<int, int>> arr;
    unordered_map<int, unordered_map<int, int>> counts;

public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0]; 
        int y = point[1];  
        arr.push_back({x, y});
        counts[x][y]++;  
    }
    
    int count(vector<int> point) {
        int dx = point[0]; 
        int dy = point[1]; 
        int endres = 0; 

        for (auto& p : arr) {
            int x = p.first;
            int y = p.second;

            if (abs(dx - x) != abs(dy - y) || dx == x || dy == y) {
                continue;
            }

            if (counts.count(dx) && counts[dx].count(y) && 
                counts.count(x) && counts[x].count(dy)) {
                endres += counts[dx][y] * counts[x][dy];
            }
        }

        return endres;
    }
};


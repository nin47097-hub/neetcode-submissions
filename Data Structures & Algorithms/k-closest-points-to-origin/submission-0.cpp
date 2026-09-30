#include <vector>
#include <queue>
class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, int>> maxHeap;
        for (int i = 0; i < points.size(); ++i) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            maxHeap.push({dist, i}); 
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        std::vector<std::vector<int>> result;
        while (!maxHeap.empty()) {
            int index = maxHeap.top().second;
            result.push_back(points[index]);
            maxHeap.pop();
        }
        return result;
    }
};


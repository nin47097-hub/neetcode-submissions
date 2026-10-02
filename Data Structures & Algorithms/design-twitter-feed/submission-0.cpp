#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Twitter {
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int count = 0;

public:
    Twitter() {
        followers.clear();
        tweets.clear();
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        count++;
        tweets[userId].push_back({count, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> jj = followers[userId];
        jj.insert(userId);

        priority_queue<pair<int, pair<int, pair<int, int>>>> maxHeap;

        for (int k : jj) {
            if (tweets.find(k) != tweets.end() && !tweets[k].empty()) {
                int last_index = tweets[k].size() - 1;
                int time = tweets[k][last_index].first;
                int tweet = tweets[k][last_index].second;
                maxHeap.push({time, {tweet, {k, last_index}}});
            }
        }

        vector<int> feed;

        while (!maxHeap.empty() && feed.size() < 10) {
            auto topElement = maxHeap.top();
            maxHeap.pop();

            int news = topElement.second.first;
            int user = topElement.second.second.first;
            int currentIdx = topElement.second.second.second;

            feed.push_back(news);

            if (currentIdx > 0) {
                int nextIdx = currentIdx - 1;
                int nextTime = tweets[user][nextIdx].first;
                int nextTweetId = tweets[user][nextIdx].second;
                maxHeap.push({nextTime, {nextTweetId, {user, nextIdx}}});
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followers.find(followerId) != followers.end()) {
            followers[followerId].erase(followeeId);
        }
    }
};

class Twitter {
private:
    int time;
    vector<set<int>> users;
    set<pair<int, pair<int, int>>, greater<>> tweets;
public:
    Twitter() {
        users = vector<set<int>>(501);
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.insert({time, {userId, tweetId}});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> answer;
        set<int> goodUsers;
        goodUsers.insert(userId);
        for(auto &x: users[userId]){
            goodUsers.insert(x);
        }
        int c = 0;


        for(auto &tweet: tweets) {
            if(answer.size() == 10) {
                return answer;
            }
            int candi = tweet.second.first;
            int candj = tweet.second.second;
            if(goodUsers.find(candi)!=goodUsers.end()){
                answer.push_back(candj);
            }
        }
        return answer;
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId);
    }
};

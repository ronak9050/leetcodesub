class Twitter {
    vector<set<int>> fol;
    vector<vector<pair<int,int>>> tw;
    int ct=0;
public:
    Twitter() {
        fol.resize(501);
        tw.resize(501);
        for(int i=0; i<500; i++) fol[i].insert(i);
    }
    
    void postTweet(int userId, int tweetId) {
        tw[userId].push_back({ct,tweetId});
        ct++;
    }

    vector<int> getNewsFeed(int u) {
        vector<int> ans;
        priority_queue<vector<int>> pq;
        for(auto &e:fol[u]){
            if(tw[e].size()){
                int curct=tw[e].back().first;
                int twid=tw[e].back().second;
                pq.push({curct,twid,e,int(tw[e].size()-2)});
            }
        }
        int num=10;
        while(num && pq.size()){
            vector<int> v=pq.top();
            pq.pop();
            num--;
            ans.push_back(v[1]);
            int uid=v[2];
            int ind=v[3];
            if(ind>=0) pq.push({tw[uid][ind].first,tw[uid][ind].second,uid,ind-1});
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        fol[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it=fol[followerId].find(followeeId);
        if(it!=fol[followerId].end()) fol[followerId].erase(it);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
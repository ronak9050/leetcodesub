class Solution {
public:
    void dfs(int node,vector<queue<int>>&g,vector<int> &order){
        while(g[node].size()){
            int cur=g[node].front();
            g[node].pop();
            dfs(cur,g,order);
        }
        order.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tick) {
        map<string,int> mp;
        map<int,string> rev;
        sort(tick.begin(),tick.end());
        set<string> st;
        for(auto &e:tick){
            st.insert(e[0]);
            st.insert(e[1]);
        }
        int ind=0;
        for(auto &e:st){
            mp[e]=ind;
            rev[ind]=e;
            ind++;
        }
        
        vector<queue<int>> g(ind);
        for(auto &e:tick){
            g[mp[e[0]]].push(mp[e[1]]);
        }
        
        vector<int> order;
        dfs(mp["JFK"],g,order);
        reverse(order.begin(),order.end());
        vector<string> ans;
        for(auto e:order){
            ans.push_back(rev[e]);
        }
        return ans;
    }
};
class Solution {
public:
    void dfs(int ind,vector<int>&a,vector<int> &vis,vector<int>&path){
        path.push_back(ind);
        if(vis[ind] || a[ind]==-1) return;
        vis[ind]=1;
        dfs(a[ind],a,vis,path);
    }

    int cycle(vector<int>&path){
        int n=path.size();
        for(int i=0; i<n-1; i++){
            if(path[i]==path[n-1]) return n-1-i;
        }
        return 0;
    }

    int longestCycle(vector<int>& a) {
        int n=a.size();
        vector<int> indeg(n,0);
        for(int i=0; i<n; i++){
            if(a[i]!=-1) indeg[a[i]]++;
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0; i<n; i++){
            if(!indeg[i]){
                vector<int> path;
                dfs(i,a,vis,path);
                ans=max(ans,cycle(path));
            }
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                vector<int> path;
                dfs(i,a,vis,path);
                ans=max(ans,cycle(path));
            }
        }
        return ans==0? -1:ans;
    }
};
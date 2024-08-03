class Solution {
public:
    
    pair<int,int> dfs(int ind,int par,int t,vector<vector<int>>&g){
        int ans=t;
        int retind=ind;
        for(auto &e:g[ind]){
            if(e==par) continue;
            pair<int,int> cur=dfs(e,ind,t+1+(e%2==0),g);
            if(ans<cur.first){
                ans=cur.first;
                retind=cur.second;
            }
        }
        return {ans,retind};
    }

    void dfs2(int ind,int par,int t,vector<vector<int>>&g,vector<int>&time){
        time[ind]=t;
        for(auto &e:g[ind]){
            if(e==par) continue;
            dfs2(e,ind,t+1+(e%2==0),g,time);
        }
    }

    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> g(n);
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        pair<int,int> d1=dfs(0,-1,0,g);
        int st=d1.second;
        pair<int,int> d2=dfs(st,-1,0,g);
        int end=d2.second;

        vector<int> time1(n,0),time2(n,0),ans(n,0);
        dfs2(st,-1,0,g,time1);
        dfs2(end,-1,0,g,time2);

        for(int i=0; i<n; i++){
            int num1=time1[i];
            if(i&1 && st%2==0) num1++;
            else if(i%2==0 && st&1) num1--;

            int num2=time2[i];
            if(i&1 && end%2==0) num2++;
            else if(i%2==0 && end&1) num2--;
            ans[i]=max(num1,num2);
        }
        return ans;
    }
};
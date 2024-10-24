class Solution {
public:
    void work(vector<int>&a,vector<int>&v){
        vector<int> tmp;
        for(auto f:v) tmp.push_back(a[f]);
        sort(tmp.begin(),tmp.end());
        sort(v.begin(),v.end());
        for(int i=0; i<v.size(); i++){
            a[v[i]]=tmp[i];
        }
        v.clear();
    }
    
    vector<int> lexicographicallySmallestArray(vector<int>& a, int limit) {
        int n=a.size();
        map<int,vector<int>> mp;
        for(int i=0; i<n; i++) mp[a[i]].push_back(i);

        int last=-1;
        vector<int> v;
        for(auto &e:mp){
            if(last!=-1 && (e.first-last)>limit){
                work(a,v);
            }
            last=e.first;
            for(auto f:e.second) v.push_back(f);
        }
        work(a,v);
        return a;
    }
};
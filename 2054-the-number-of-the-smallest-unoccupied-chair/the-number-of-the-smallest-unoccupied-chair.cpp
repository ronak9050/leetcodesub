class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int tar){
        set<int> st; // [chair]
        int n=times.size();
        for(int i=0; i<n; i++) st.insert(i);

        vector<vector<int>> a; // [tin,tout,ind]
        for(int i=0; i<n; i++){
            a.push_back({times[i][0],times[i][1],i});
        }
        sort(a.begin(),a.end());

        set<vector<int>> rem;  // [tout,chair]
        for(int i=0; i<n; i++){
            int t=a[i][0],lve=a[i][1];
            while(rem.size() && rem.begin()->at(0)<=t){
                st.insert(rem.begin()->at(1));
                rem.erase(rem.begin());
            }
            if(a[i][2]==tar) return *st.begin();
            rem.insert({lve,*st.begin()});
            st.erase(st.begin());
        }

        return -1;
    }
};
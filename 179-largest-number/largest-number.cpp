class Solution {
public:
    static bool cmp(string &a,string &b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> a;
        for(auto e:nums) a.push_back(to_string(e));
        sort(a.begin(),a.end(),cmp);
        
        if(a[0]=="0") return "0";
        string ans;
        for(auto &e:a){
            for(auto f:e) ans.push_back(f);
        }
        return ans;
    }
};
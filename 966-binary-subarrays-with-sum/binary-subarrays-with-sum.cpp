class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0,n=nums.size();
        map<int,int> mp;
        int sum=0;
        mp[sum]++;
        for(int i=0; i<n; i++){
           sum+=nums[i];
           mp[sum]++;
           ans+=mp[sum-goal];
           if(goal==0) ans--;
        }
        return ans;
    }
};
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        if (hand.size() % gs != 0) return false;
        unordered_map<int, int> mp;
        for (int card : hand) mp[card]++;

        for (int card : hand){
            int st = card;
            while (mp[st - 1]) st--;
            while (mp[st]) {
                for (int nc = st; nc < st + gs; nc++) {
                    if (!mp[nc]) return false;
                    mp[nc]--;
                }
            }
            st++;
        }

        return true;
    }
};
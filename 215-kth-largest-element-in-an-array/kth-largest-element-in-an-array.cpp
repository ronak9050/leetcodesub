class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        priority_queue<int> pq;
        for(auto &e:a) pq.push(e);
        for(int i=0; i<k-1; i++) pq.pop();
        return pq.top();
    }
};
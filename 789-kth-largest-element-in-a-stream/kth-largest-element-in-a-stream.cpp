class KthLargest {
public:
    priority_queue <int> pq;
    int kp;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]*(-1));
        }
        kp=k;
        while(pq.size()>k){
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val*(-1));
        while(pq.size()>kp){
            pq.pop();
        }
        return (-1)*pq.top();
    }
};
class MedianFinder {
public:
    priority_queue<int> mx;
    priority_queue<int,vector<int>,greater<int>> mn;

    MedianFinder(){
        
    }
    
    void addNum(int num){
        mx.push(num);
        if(mn.size() && mx.top()>mn.top()){
            int xx=mx.top();
            mx.pop();
            mx.push(mn.top());
            mn.pop();
            mn.push(xx);
        }
        if(mx.size()-mn.size()>1){
            mn.push(mx.top());
            mx.pop();
        }
    }
    
    double findMedian(){
        int sum=mx.size()+mn.size();
        if(sum&1) return mx.top();
        return (mx.top()+mn.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
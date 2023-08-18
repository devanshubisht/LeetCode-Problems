class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i = 0 ; i < nums.size(); i++) {
            if ((pq.size() >= k) && (pq.top() < nums[i] )){
                this->pq.pop();
                this->pq.push(nums[i]);
            } else {
                if (pq.size() < k) {
                    pq.push(nums[i]);
                }
            }
        }
    
    }
    
    int add(int val) {
        if (pq.size() < k) {
            pq.push(val);
            return pq.top();
        }
        if (pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

 // create a heap. everytime u add u add to the heap. the for the kth largest. js pop 
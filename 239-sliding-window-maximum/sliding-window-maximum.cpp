class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);

        for (int i = k; i < nums.size(); i++) {
            if(dq.front() == i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};

// approach -> 1, 3, -1 = get max for the firsk k elements
// before move check if left is the max. if it is, then have it stored as curr
// -> move by 1.
// ->  if the right value is greater than the max then that is the value.. if smaller than max
// if the left was the max value, find new max value.

// correct approach -> move along. add to queue for the first k. the indeces are added to the queue but only if the nums[i] is bigger than the front. keep popping. 
// so the queue contains the largest numbers in those indices. do for the first window first.

//continue to the next index. if teh first index is diff is away from the allowed then pop it.
// -> deque.
// -> dq.back() [get the irest index]. pop_back t remove tyhe first one.
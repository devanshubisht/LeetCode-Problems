class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> hm;
        for (int i = 0; i < tasks.size(); i++) {
            hm[tasks[i]]++;
        }
        priority_queue<int> pq;
        for (auto a : hm) {
            pq.push(a.second);  
        }
        int time = 0;
        while (1) {
            vector<int> remain;
            int cycle = n + 1;
            while (cycle and !pq.empty()) {
                int first = pq.top();
                pq.pop();
                if (first > 1) {
                    remain.push_back(first -1);
                }
                cycle--;
                time++;
            }

            for (int count:remain) {
                pq.push(count);
            }
            if (pq.empty()) {
                break;
            }
            time += cycle;

        }
        return time;
    }
};

// Aproach. Pair and then put into a heap. pop out of the heap and add tgth. 
//  take out 
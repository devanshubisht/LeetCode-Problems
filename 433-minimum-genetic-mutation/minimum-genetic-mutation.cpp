class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        std::queue<string> q;

        q.push(startGene);

        int mutation = 0;

        if (startGene == endGene) {
            return mutation;
        }

        unordered_map<string,bool> hm;

        while (!q.empty()) {
            int initialSize = q.size();
            for (int i = 0 ; i < initialSize; i++) {
                string val = q.front();
                q.pop();
                hm[val]=true;
                if (val == endGene) {
                    return mutation;
                }
                for(int j = 0 ; j < bank.size() ; j++) {
                    if(hm[bank[j]]!= true && validMutation(val, bank[j])) {
                        q.push(bank[j]);
                    }
                }
            }
            mutation++;
        }
        return -1;
    }

    bool validMutation(string& startGene, string& nextGene) {
        int result = 0;
        for (int i = 0 ; i < startGene.size() ; i++) {
            if (startGene[i] != nextGene[i]) {
                result++;
            }
        }

        if (result == 1) {
            return true;
        }
        return false;
    }
};
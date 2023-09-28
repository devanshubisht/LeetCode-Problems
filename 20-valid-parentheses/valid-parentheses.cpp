class Solution {
public:
    bool isValid(string s) {
        std::stack<char> container;
        std::unordered_map<char, char> hm = {
    {')', '('},
    {'}', '{'},
    {']', '['}
};

        // we need keep track of the things we have encountered in the past and use it in future.

        for (auto c : s) {
            // need make sure container is not empty!!!!
            if (!container.empty() && hm[c] == container.top()) {
                container.pop();
            } else {
                container.push(c);
            }
        }
        
        return container.empty();
    }
};
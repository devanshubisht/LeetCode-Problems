class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> line;
        for(auto& i : intervals){
            ++line[i[0]];
            --line[i[1]];
        }
       
        int count = 0;
        vector<vector<int>> ans;
        int start = 0;
        for(auto& i : line){
            // that means its a new start, store the start
           if(count ==0){
               start = i.first;
           }
           count += i.second;
           // this mean interval ends, and we can push this as answer
           if(count==0){
               ans.push_back({start, i.first});
           }
        }
        return ans;
    }
}; 


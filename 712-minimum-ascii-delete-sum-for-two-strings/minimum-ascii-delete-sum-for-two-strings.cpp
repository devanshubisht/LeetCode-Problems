class Solution {
public:
    vector<vector<int>> dp; // we will store all our answers here and then get values for all future references
    
    int dead_end_sum(string &s , int i) // one of the string id empty , so all ASCII sums from ith character till end of string
    {
        int sum = 0;
        for( ; i<s.length() ; i++)
            sum+=int(s[i]);
        return sum;
    }
    
    int sub(string &a, string &b, int i, int j) // sub problem
    {
        int n = a.length();
        int m = b.length();
        int sum = 0;
        if(i==n || j==m)
        {
            if(i==n and j==m)   return 0;
            return (i==n) ? dead_end_sum(b,j) : dead_end_sum(a,i);
        }
        
        if(dp[i][j] != -1)            return dp[i][j];      // we know the answer so no need to recompute , reture it as it is.
    
        if(a[i] == b[j])
            sum = sub(a,b,i+1,j+1);
        else
        {
            sum = min({ sub(a,b,i+1,j) + int(a[i]) ,                // option  1
                        sub(a,b,i,j+1) + int(b[j])});              // option 2
        }      
        dp[i][j] = sum;     // we store our answer at each step
        return sum;
    }
    int minimumDeleteSum(string a, string b) {
        
        // making of DP matrix to store result and initilizing it to -1
        dp = vector<vector<int>>(a.length()+1, vector<int>(b.length()+1 , -1));
        return sub(a,b,0,0);
        
        return 0;
    }
};

// remove 

//  sea  eat 

// recursion to see whats the same 
// s  e  a || e  a  t
// 
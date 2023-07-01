class Solution(object):
    def distributeCookies(self, cookies, k):
        """
        :type cookies: List[int]
        :type k: int
        :rtype: int
        """
        cookies.sort(reverse = True)
        bucket = [0]*k
        self.ans = float('inf')

        def dfs(i, bucket):
            if i == len(cookies):
                self.ans = min(self.ans, max(bucket))
                return
            
            for j in range(k): # At each branch you are making 3 decisions. to include in that bucket or the other bucket
                if bucket[j]+cookies[i] <= self.ans:
                    bucket[j]+=cookies[i]
                    dfs(i+1, bucket)
                    bucket[j]-=cookies[i]

                if bucket[j] == 0: 
                    break
            return

        dfs(0, bucket)
        return self.ans

# Update: Optimization
# Let cookies = [8,15,10] and k=2.
# Then the subsets we calculate are [33,0] , [23,10], [18,15], [8,25], [25,8], [15,18], [10,23], [0,33].
# Here we observe [33,0] and [0,33] refers to same subset and similary other.
# So we can reduce the duplicates by breaking the loop if v[i] is equal to 0, as it will be covered in the other subset.
# In the for loop of above code, we break the loop if v[i] is equal to 0, because without this line we are just calculating the same subset with different combinations which is unnecessary.
# So now the subsets we calculate will only be: [33,0] , [23,10], [18,15], [8,25].
# Time complexity : O(k^n) k is the number of splits and n is the number of levels

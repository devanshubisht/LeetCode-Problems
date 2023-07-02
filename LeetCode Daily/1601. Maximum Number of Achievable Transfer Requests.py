class Solution(object):
    def maximumRequests(self, n, requests):
        """
        :type n: int
        :type requests: List[List[int]]
        :rtype: int
        """
        d = {}
        for num in range(n):
            d[num] = 0
        
        res = [float('-inf')]
        def dfs(index, d, accepted):
            if index == len(requests):
                for num in d.values():
                    if num != 0:
                        return
                res[0] = max(res[0], accepted)
                return
                
            
            out, into = requests[index][0], requests[index][1]
            d[out] -= 1
            d[into] += 1
            dfs(index + 1,d, accepted +1 )
            d[out] += 1
            d[into] -= 1
            dfs(index+1, d, accepted)
        dfs(0, d, 0)
        return res[0]

# this how i talked thru it:

# - tried linearly first but some test cases faile
# - failing because if we do linearly aka greedy , for the cases not in examples, the decision we make at that index affects the result for the future so this means we cant use greedy
# - need to use recursion
# try to figure out what should be the decisions made at each index
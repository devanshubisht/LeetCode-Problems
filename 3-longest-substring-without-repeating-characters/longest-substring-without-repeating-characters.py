class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        right = 0 
        left = 0
        res = 0
        hm = {}

        while right < len(s):
            if s[right] not in hm:
                hm[s[right]] =0
            hm[s[right]]+=1

            # condition for the sliding window
            while hm[s[right]] > 1:
                hm[s[left]] -= 1
                left+=1
            
            res = max(res, right - left +1)
            right +=1
        return res

        


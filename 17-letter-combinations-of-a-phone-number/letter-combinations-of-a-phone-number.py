class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        res = []
        digitToChar = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "qprs",
            "8": "tuv",
            "9": "wxyz",
        }
        def backtrack(i, curr):
            if len(curr) == len(digits):
                res.append(curr)
                return
            for char in digitToChar[digits[i]]:
                curr = curr + char
                backtrack(i+1, curr)
                curr = curr[:-1]
        if digits:
            backtrack(0, "")
        return res


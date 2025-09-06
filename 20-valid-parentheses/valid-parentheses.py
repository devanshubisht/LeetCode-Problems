class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        ls = []
        hm = {
            '(': ')',
            '{': '}',
            '[': ']'
        }
        for i in s:
            if i in ['(', '{', '[']:
                ls.append(i)
                continue
            if len(ls) == 0:
                return False
            if i == hm[ls[-1]]:
                ls.pop(-1)
            else:
                return False
        if len(ls) == 0:
            return True
        return False

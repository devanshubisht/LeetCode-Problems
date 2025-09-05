class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        set = {}

        for str in strs:
            sorted_str = ''.join(sorted(str))
            if sorted_str in set:
                set[sorted_str].append(str)
            else:
                set[sorted_str] = [str]

        return list(set.values())

        
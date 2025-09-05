class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        a = []
        for num in range(len(nums)):
            left = num + 1
            right = len(nums) - 1
            if num > 0 and nums[num -1] == nums[num]:
                continue
            while left < right:
                threeSum = nums[left] + nums[right] + nums[num]
                if threeSum > 0:
                    right = right -1
                elif threeSum < 0:
                    left += 1
                else: 
                    a.append([nums[num], nums[left], nums[right]])
                    left += 1
                    while nums[left - 1] == nums [ left] and left < right:
                        left += 1
        return a


class Solution:
    def halveArray(self, nums: List[int]) -> int:
        total = sum(nums)
        D = total / 2.0
        heap = [-x for x in nums]     # max-heap via negatives
        heapq.heapify(heap)

        ops = 0
        while D > 0:
            x = -heapq.heappop(heap)  # largest current value
            D -= x / 2.0
            heapq.heappush(heap, -(x / 2.0))
            ops += 1
        return ops
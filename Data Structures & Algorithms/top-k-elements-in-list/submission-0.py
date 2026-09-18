import heapq
from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        result = []

        count = Counter(nums)

        for num, freq in count.items():
            result.append((-freq,num))


        heapq.heapify(result)
        ans = []

        for i in range(k):
            freq, num = heapq.heappop(result)
            ans.append(num)

        return ans
       



        
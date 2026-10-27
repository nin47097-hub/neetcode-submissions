class Solution(object):
    def maxProduct(self, nums):
        curren_max = 1
        current_min =1
        result = max(nums)

        for n in nums:

            
            temp_max = curren_max * n
            curren_max = max(curren_max*n, n*current_min,n)
            current_min = min(temp_max, n*current_min,n)

            result = max(result, curren_max)


        return result

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums.sort()
        if not nums :
            return 0

        nums.sort()
        current_long = 1
        max_long = 1

        for i in range(1,len(nums)):
            if nums[i]== nums[i-1]:
                continue


            if nums[i]==nums[i-1]+1:
                current_long+=1

            else:
                max_long= max(max_long, current_long)
                current_long =1


        return max(max_long, current_long)

        
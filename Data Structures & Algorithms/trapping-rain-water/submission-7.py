class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n==0:
            return 0

        left = [0]*len(height)
        right=[0]*len(height)
        right[n-1]=height[n-1]
        left[0]= height[0]

        

        for i in range(1,len(height)):
            left[i] = max(height[i], left[i-1])

        for i in range(n-2,-1,-1):
            right[i] = max(height[i], right[i+1])


        x=0
        for i in range(len(height)):
            x+= min(left[i], right[i]) -height[i]




        return x
        
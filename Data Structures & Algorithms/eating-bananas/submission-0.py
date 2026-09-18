class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        right = max(piles)
        

        while l<= right:
            m = (l+ right)//2
            time =0

            for p in piles:
                time += math.ceil(p/m)


            if(time<=h):
                right=m-1


            elif(time>h):
                l = m+1

          

        return l


            
        
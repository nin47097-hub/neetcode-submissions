class Solution(object):
    def mergeTriplets(self, triplets, target):
      
        maxarray = [0, 0, 0]

        for t in triplets:
          
            if t[0] > target[0] or t[1] > target[1] or t[2] > target[2]:
                continue

            
            maxarray[0] = max(maxarray[0], t[0])
            maxarray[1] = max(maxarray[1], t[1])
            maxarray[2] = max(maxarray[2], t[2])
            
          
            if maxarray == target:
                return True

        return maxarray == target

            
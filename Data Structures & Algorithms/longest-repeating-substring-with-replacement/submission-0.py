class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        c={}
        left =0
        max_len =0
        
        for i in range(len(s)):
            c[s[i]]= 1+c.get(s[i],0)
            
            while(((i-left+1)-max(c.values())>k)):
                
                c[s[left]]-=1
                left+=1

            max_len = max(max_len,(i-left+1))


        return max_len




            

             




        
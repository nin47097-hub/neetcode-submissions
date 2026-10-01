class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freq = {}
        count =0

        for k in tasks:
            freq[k]= freq.get(k,0)+1

        max_freq = max(freq.values())

        for i in freq:
            if(freq[i])==max_freq:
                count+=1

        return max(len(tasks),  (max_freq - 1) * (n + 1) + count)



        
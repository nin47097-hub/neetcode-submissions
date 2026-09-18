class TimeMap:

    def __init__(self):
        self.store = {}
        

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.store:
            self.store[key] = []
        
        self.store[key].append([timestamp, value])
        

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.store:
            return ""

        h = self.store[key]
        res = ""
        high = len(h) - 1
        low = 0
      
        while low <= high:
            mid = (low + high) // 2

            if h[mid][0] <= timestamp:
                res = h[mid][1] 
                low = mid + 1
            else:
               
                high = mid - 1
                
        return res
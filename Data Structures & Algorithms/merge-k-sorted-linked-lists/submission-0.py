# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        c=[]
        k = ListNode(0)
        curr = k

        for i in lists:
            while i:
                c.append(i.val)

                i = i.next


        c.sort()

        for n in c:
            curr.next = ListNode(n)
            curr= curr.next


        return k.next

        
        
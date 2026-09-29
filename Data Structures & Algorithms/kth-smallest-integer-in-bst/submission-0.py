# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:

        smallarray=[]
        def inorder(node):
            if not node:
                return 0

            inorder(node.left)
            smallarray.append(node.val)
            inorder(node.right)

        inorder(root)


        smallarray.sort()
      

        return smallarray[k-1]
        
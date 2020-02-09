# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        list1 = [root]

        candidate = None
        while len(list1) > 0:
            candidate = list1[0]
            list2 = []
            for node in list1:
                if node.left is not None:
                    list2.append(node.left)
                if node.right is not None:
                    list2.append(node.right)
            list1 = list2
        return candidate.val


import unittest

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        root = TreeNode(2)
        root.left = TreeNode(1)
        root.right = TreeNode(3)
        self.assertEqual(1, self.solution.findBottomLeftValue(root))

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
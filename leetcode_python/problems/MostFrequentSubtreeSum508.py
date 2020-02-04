import unittest


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """


class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        pass

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
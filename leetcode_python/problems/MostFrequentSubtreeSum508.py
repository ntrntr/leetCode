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
        ret = {}
        root and self.getValue(root, ret)
        current_count = 0
        return_value = []
        for k, v in ret.iteritems():
            if v > current_count:
                current_count = v
                return_value = []
                return_value.append(k)
            elif v == current_count:
                return_value.append(k)
        return return_value

    def getValue(self, root, ret):
        leftValue = 0
        rightValue = 0
        if root.left:
            leftValue = self.getValue(root.left, ret)
        if root.right:
            rightValue = self.getValue(root.right, ret)
        total = root.val + leftValue + rightValue
        ret[total] = ret.get(total, 0) + 1
        return total


class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        node1 = TreeNode(5)
        node1.left = TreeNode(2)
        node1.right = TreeNode(-3)
        self.assertEqual([-3,2,4], sorted(self.solution.findFrequentTreeSum(node1)))

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
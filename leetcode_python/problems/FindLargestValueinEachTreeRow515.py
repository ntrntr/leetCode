import unittest


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ret = []
        list1 = [root] if root else []
        while len(list1) > 0:
            candidate = list1[0].val
            list2 = []
            for node in list1:
                candidate = max(candidate, node.val)
                if node.left is not None:
                    list2.append(node.left)
                if node.right is not None:
                    list2.append(node.right)
            list1 = list2
            ret.append(candidate)
        return ret


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
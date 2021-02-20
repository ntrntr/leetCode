import unittest

"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Node
        :rtype: List[List[int]]
        """
        ret = []
        datas = [root] if root else []
        while datas:
            new_line = []
            next_datas = []
            for item in datas:
                new_line.append(item.val)
                if item.children:
                    for tmp in item.children:
                        next_datas.append(tmp)
            ret.append(new_line)
            datas = next_datas
        return ret

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        self.assertEqual(self.solution.levelOrder(None), None)

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
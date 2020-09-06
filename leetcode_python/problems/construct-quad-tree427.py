import unittest
# Definition for a QuadTree node.
class Node(object):
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight


class Solution(object):
    def construct(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: Node
        """
        grid_size = len(grid)
        return self._generate(grid, 0, grid_size-1, 0, grid_size-1, None)

    def _generate(self, grid, row_begin, row_end, col_begin, col_end, parent=None):
        if row_begin == row_end and col_begin == col_end:
            # the only node
            node = Node(grid[row_begin][col_begin], True, None, None, None, None)
        return parent


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
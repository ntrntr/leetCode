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
    # top 0 bottom 1 left 0 right 1
    ROOT = -1
    TL = 0
    TR = 2
    BL = 1
    BR = 3
    def construct(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: Node
        """
        grid_size = len(grid)
        ret = self._generate(grid, 0, grid_size-1, 0, grid_size-1, None)
        return ret

    def printNode(self, node):
        list1 = [node]
        list2 = []
        while list1:
            while list1:
                node = list1.pop(0)
                print 'node:%s, isLeaf:%s\t' % (node.val, node.isLeaf)
                if not node.isLeaf:
                    list2.append(node.topLeft)
                    list2.append(node.topRight)
                    list2.append(node.bottomLeft)
                    list2.append(node.bottomRight)
            list1 = list2
            list2 = []
            print "-----------------------\n"


    def _generate(self, grid, row_begin, row_end, col_begin, col_end, current=None):
        if current is None:
            current = Node(0, False, None, None, None, None)
        if row_begin == row_end and col_begin == col_end:
            # the only node
            val = grid[row_begin][col_begin]
            current.val = val
            current.isLeaf = True
        else:
            # judge judge_equal
            all_equal = True
            val = grid[row_begin][col_begin]
            for i in range(row_begin, row_end + 1, 1):
                for j in range(col_begin, col_end+1, 1):
                    if grid[i][j] != val:
                        all_equal = False
                        break
                if not all_equal:
                    break
            if all_equal:
                current.val = val
                current.isLeaf = True
            else:
                c_size = row_end - row_begin + 1
                half_size = c_size / 2
                current.topLeft = self._generate(grid, row_begin, row_begin + half_size - 1, col_begin, col_begin + half_size - 1)
                current.topRight = self._generate(grid, row_begin, row_begin + half_size - 1, col_end - half_size + 1, col_end)
                current.bottomLeft = self._generate(grid, row_end - half_size + 1, row_end, col_begin, col_begin + half_size - 1)
                current.bottomRight = self._generate(grid, row_end - half_size + 1, row_end, col_end - half_size + 1, col_end)
        return current

    def method_name(self, parent, type, val):
        node = Node(val, True, None, None, None, None)
        if type == -1:
            parent.val = val
            parent.isLeaf = True
        elif type == self.TL:
            parent.topLeft = node
        elif type == self.TR:
            parent.topRight = node
        elif type == self.BL:
            parent.bottomLeft = node
        elif type == self.BR:
            parent.bottomRight = node
        return node


class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()


    def test_something1(self):
        # self.solution.construct([[1,1],[1,1]])
        # self.solution.construct([[1,1],[1,0]])

        # self.assertTrue(True, "")
        self.assertEqual(3, self.solution.construct([[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]))

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
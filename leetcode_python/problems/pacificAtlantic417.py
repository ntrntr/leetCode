import unittest


class Solution(object):
    TYPE_NONE = 0
    TYPE_P = 1 << 0
    TYPE_A = 1 << 1
    def pacificAtlantic(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        row = len(matrix)
        col = len(matrix[0])
        state = [ [self.TYPE_NONE] * col for i in range(row)]
        for i in xrange(row):
            state[i][0] |= self.TYPE_P
            state[i][col-1] |= self.TYPE_A
        for j in xrange(col):
            state[0][j] |= self.TYPE_P
            state[row-1][j] |= self.TYPE_A
        for i in range(0, row):
            for j in range(0, col):
                if state[i][j] & self.TYPE_P:
                    self.flowValue(state, i, j, col, row, self.TYPE_P)
        for i in range(row-1, 0, -1):
            for j in range(col-1, 0, -1):
                if state[i][j] & self.TYPE_A:
                    self.flowValue(state, i, j, col, row, self.TYPE_A)
        return [(i, j) for j in range(col) for i in range(row) if state[i][j] == 3]


    def flowValue(self, state, i, j, col, row, type):
        # left
        if j - 1 >= 0 and state[i][j-1] <= state[i][j]:
            state[i][j] |= type
        # right
        if j + 1 <= col - 1 and state[i][j+1] <= state[i][j]:
            state[i][j+1] |= type
        # top
        if i - 1 >= 0 and state[i - 1][j] <= state[i][j]:
            state[i - 1][j] |= type
        # down
        if i + 1 <= row - 1 and state[i + 1][j] <= state[i][j]:
            state[i + 1][j] |= type




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
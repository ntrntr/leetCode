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
            self.flowValue(state, i, 0, col, row, self.TYPE_P, matrix)
            state[i][col-1] |= self.TYPE_A
            self.flowValue(state, i, col-1, col, row, self.TYPE_A, matrix)
        for j in xrange(col):
            state[0][j] |= self.TYPE_P
            self.flowValue(state, 0, j, col, row, self.TYPE_P, matrix)
            state[row-1][j] |= self.TYPE_A
            self.flowValue(state, row-1, j, col, row, self.TYPE_A, matrix)
        # print "state", state
        finnal_ret = []
        for i in range(row):
            for j in range(col):
                if state[i][j] == 3:
                    finnal_ret.append((i, j,))
        return finnal_ret

    def flowValue(self, state, i, j, col, row, type, matrix):
        # left
        if j - 1 >= 0 and matrix[i][j-1] >= matrix[i][j] and not (state[i][j-1] & type):
            state[i][j-1] |= type
            self.flowValue(state, i, j-1, col, row, type, matrix)
        # right
        if j + 1 <= col - 1 and matrix[i][j+1] >= matrix[i][j] and not (state[i][j+1] & type):
            state[i][j+1] |= type
            self.flowValue(state, i, j+1, col, row, type, matrix)
        # top
        if i - 1 >= 0 and matrix[i - 1][j] >= matrix[i][j] and not (state[i-1][j] & type):
            state[i - 1][j] |= type
            self.flowValue(state, i-1, j, col, row, type, matrix)
        # down
        if i + 1 <= row - 1 and matrix[i + 1][j] >= matrix[i][j] and not (state[i+1][j] & type):
            state[i + 1][j] |= type
            self.flowValue(state, i+1, j, col, row, type, matrix)


  # Pacific ~   ~   ~   ~   ~
  #      ~  1   2   2   3  (5) *
  #      ~  3   2   3  (4) (4) *
  #      ~  2   4  (5)  3   1  *
  #      ~ (6) (7)  1   4   5  *
  #      ~ (5)  1   1   2   4  *
  #         *   *   *   *   * Atlantic


class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        solution = Solution()
        ret = solution.pacificAtlantic([[1,2,2,3,5],\
                                  [3,2,3,4,4],\
                                  [2,4,5,3,1],\
                                  [6,7,1,4,5],\
                                  [5,1,1,2,4]])
        print ret

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
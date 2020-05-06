import unittest


class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        rows = len(board)
        cols = len(board[-1])
        ret = 0
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == 'X':
                    ret += 1
                    self.modifyBoard(board, i, j)
        return ret

    def modifyBoard(self, board, x, y):
        board[x][y] = '.'
        rows = len(board)
        cols = len(board[-1])
        for i in range(x + 1, rows):
            if board[i][y] == '.':
                break
            board[i][y] = '.'
        for j in range(y + 1, cols):
            if board[x][j] == '.':
                break
            board[x][j] = '.'

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
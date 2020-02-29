import unittest


class Solution(object):
    def LCS(self, s1, s2):
        s1_len = len(s1)
        s2_len = len(s2)
        state = [[0] * (s2_len + 1) for i in range(s1_len+1)]
        for i in xrange(s1_len-1,-1,-1):
            for j in xrange(s2_len-1,-1,-1):
                if s1[i] == s2[j]:
                    state[i][j] = state[i+1][j+1] + 1
                else:
                    state[i][j] = max(state[i+1][j], state[i][j+1])

        return state[0][0]

    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        return self.LCS(s, ''.join(reversed(s)))

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        self.assertEqual(4, self.solution.longestPalindromeSubseq("bbbab"))

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
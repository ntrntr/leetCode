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

    def lcs(self, a, b):
        len_a = len(a)
        len_b = len(b)
        state = [[0] * (len_b + 1) for i in range(len_a + 1)]
        for i in xrange(len_a - 1, -1, -1):
            for j in xrange(len_b - 1, -1, -1):
                if a[i] == b[j]:
                    state[i][j] = state[i+1][j+1] + 1
                else:
                    state[i][j] = max(state[i][j+1], state[i+1][j])
        return state[0][0]


    def findLUSlength(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: int
        """
        if len(a) == 0 and len(b) == 0:
            return -1
        if len(a) == 0 or len(b) == 0:
            return max(len(a), len(b))
        if len(a) != len(b):
            return len(a) if len(a) > len(b) else len(b)
        if a != b:
            return len(a)
        else:
            return -1


class MyTestCase(unittest.TestCase):

    def setUp(self):
        pass

    def test_something1(self):
        solution = Solution()
        # self.assertEqual(solution.findLUSlength("aba", "cdc"), 3)
        self.assertEqual(solution.findLUSlength("aaa", "aaa"), -1)
        self.assertEqual(solution.findLUSlength("aefawfawfawfaw", "aefawfeawfwafwaef"), 17)

    def test_something2(self):
        solution = Solution()

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
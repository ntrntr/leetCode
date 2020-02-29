import unittest


class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        s_len = len(s)
        ret = 0
        dp = [[False] * s_len for i in range(s_len) ]
        for i in range(s_len-1,-1,-1):
            for j in range(i, s_len):
                dp[i][j] = s[i] == s[j] and (j - i < 3 or dp[i + 1][j - 1])
                if dp[i][j]:
                    ret += 1
        return ret

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        self.assertEqual(3, self.solution.countSubstrings("abc"))
        self.assertEqual(6, self.solution.countSubstrings("aaa"))


    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
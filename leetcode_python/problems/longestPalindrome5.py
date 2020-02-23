class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        s_len = len(s)
        if s_len <= 1:
            return s
        max_len = 1
        begin = 0
        for i in range(s_len):
            left = i -1
            right = i + 1
            while left >=0 and right < s_len and s[left] == s[right]:
                if right - left + 1 >  max_len:
                    max_len = right - left + 1
                    begin = left
                left = left - 1
                right = right + 1
            left = i
            right = i + 1
            while left >=0 and right < s_len and s[left] == s[right]:
                if right - left + 1 >  max_len:
                    max_len = right - left + 1
                    begin = left
                left = left - 1
                right = right + 1
        return s[begin:begin + max_len]


import unittest

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        self.assertEqual(self.solution.longestPalindrome("babad"), "bab")

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
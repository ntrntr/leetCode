import unittest


class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        s_len = len(s)
        if s_len <= k + 1:
            return s_len



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
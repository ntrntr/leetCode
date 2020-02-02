class Solution(object):

    Cache = {1 : 0, 2 : 1, }

    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """

        if self.Cache.has_key(n):
            return self.Cache[n]
        if n % 2 == 0:
            ret = 1 + self.integerReplacement(n // 2)
            self.Cache[n] = ret
            return ret
        else:
            ret = min(1 + self.integerReplacement(n + 1), 1 + self.integerReplacement(n - 1))
            self.Cache[n] = ret
            return ret


import unittest

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        self.assertEqual(self.solution.integerReplacement(1), 0)
        self.assertEqual(self.solution.integerReplacement(2), 1)
        self.assertEqual(self.solution.integerReplacement(3), 2)
        self.assertEqual(self.solution.integerReplacement(8), 3)
        self.assertEqual(self.solution.integerReplacement(7), 4)

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
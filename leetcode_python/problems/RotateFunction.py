class Solution(object):
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if len(A) <= 1:
            return 0
        current_sum = 0
        import sys
        ret = -sys.maxint
        for index, value in enumerate(A):
            current_sum = current_sum + index * value
        ret = max(ret, current_sum)
        n = len(A)
        sum_A = sum(A)
        for i in range(1, n):
            current_sum = current_sum + sum_A - n * A[n - i]
            ret = max(ret, current_sum)
        return ret


import unittest

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        # self.assertEqual(self.solution.maxRotateFunction([4, 3, 2, 6]), 26)
        self.assertEqual(self.solution.maxRotateFunction([-2147483648,-2147483648]), -2147483648)


    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
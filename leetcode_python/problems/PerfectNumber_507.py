import math
import unittest


class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num < 0:
            return False
        if num == 1:
            return False
        ret = 1
        for i in xrange(2, int(math.ceil(math.sqrt(num)))):
            if num % i == 0:
                # print i, num // i
                ret = ret + i + (num // i)
        return ret == num


class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        self.assertEqual(True, self.solution.checkPerfectNumber(6))

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None


if __name__ == '__main__':
    unittest.main()

# coding=utf-8
import unittest


class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums_len = len(nums)
        nums_sum = sum(nums)
        nums_min = min(nums)
        return nums_sum -nums_len * nums_min


class MyTest(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def tearDown(self):
        self.solution = None

    def test_case1(self):
        print "abbbbbc"
        # self.assertEqual(1,2)
        self.assertEqual(self.solution.minMoves([1,2,3]), 3, (3,))
        self.assertEqual(self.solution.minMoves([1]), 0, (0,))
        self.assertEqual(self.solution.minMoves([1,2]), 1, (1,))
        self.assertEqual(self.solution.minMoves([2,5,5]), 5, (1,))

if __name__ == "__main__":
    unittest.main()
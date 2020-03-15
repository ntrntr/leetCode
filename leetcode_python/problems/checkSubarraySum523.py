import unittest


class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        if len(nums) <= 1:
            return False
        right_sum = [0]
        current = 0
        for num in nums:
            current += num
            right_sum.append(current)
        num_len = len(nums)
        for i in xrange(1,num_len+1):
            for j in xrange(i+1, num_len+1):
                if k == 0:
                    if (right_sum[j] - right_sum[i-1]) == 0:
                        return True
                else:
                    if (right_sum[j] - right_sum[i-1]) % k == 0:
                        return True
        return False


class MyTestCase(unittest.TestCase):

    def setUp(self):
        pass

    def test_something1(self):
        solution = Solution()
        ret = solution.checkSubarraySum([23, 2, 6, 4, 7], 6)
        self.assertEqual(ret, True)
        ret = solution.checkSubarraySum([23, 2, 6, 4, 7], 0)
        self.assertEqual(ret, False)
        ret = solution.checkSubarraySum([0], 0)
        self.assertEqual(ret, False)

    def test_something2(self):
        solution = Solution()
        ret = solution.checkSubarraySum([23, 2, 4, 6, 7], 6)
        self.assertEqual(ret, True)

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
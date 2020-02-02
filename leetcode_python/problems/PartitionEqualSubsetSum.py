# class Solution(object):
#     def canPartition(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: bool
#         """
#         all_sum = sum(nums)
#         if all_sum % 2 != 0:
#             return False
#         nums.sort()
#         expect_sum = all_sum // 2
#         return self.dfs(0, 0, nums, expect_sum)
#
#     def dfs(self, index, cur_sum, nums, expected_sum):
#         if cur_sum == expected_sum:
#             return True
#         if cur_sum > expected_sum:
#             return False
#         if index >= len(nums):
#             return False
#         # not add to
#         ret = self.dfs(index+1, cur_sum, nums, expected_sum)
#         if ret:
#             return True
#         # add to
#         return self.dfs(index+1, cur_sum + nums[index], nums, expected_sum)

class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        all_sum = sum(nums)
        if all_sum % 2 != 0:
            return False
        nums.sort()
        expect_sum = all_sum // 2
        sum_set = set([])
        for num in nums:
            # add
            add_num = set([t + num for t in sum_set if t + num <= expect_sum])
            add_num.add(num)
            # not add
            sum_set.update(add_num)
            # print sum_set
            if expect_sum in sum_set:
                return True
        return False

import unittest

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something(self):
        self.assertEqual(self.solution.canPartition([1, 5, 11, 5]), True)


if __name__ == '__main__':
    unittest.main()
class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        nums_sum = sum(nums)
        if nums_sum % k != 0:
            return False
        expect_num = nums_sum // k
        nums.sort()
        if nums[-1] > expect_num:
            return False
        return self.dfs(0, [0] * len(nums), 0, expect_num, nums, k)

    def dfs(self, index, select_info, cur_sum, expect_num, nums, k):
        if k == 0:
            return True
        if cur_sum == expect_num:
            new_nums = [num for info, num in zip(select_info, nums) if info != 1]
            return self.dfs(0, [0] * len(new_nums), 0, expect_num, new_nums, k - 1)
        if cur_sum > expect_num:
            return False
        if index >= len(nums):
            return False
        # not add to
        select_info[index] = 2
        ret = self.dfs(index + 1, select_info, cur_sum, expect_num, nums, k)
        select_info[index] = 0
        if ret:
            return True
        # add to
        select_info[index] = 1
        ret = self.dfs(index + 1, select_info, cur_sum + nums[index], expect_num, nums, k)
        select_info[index] = 0
        return ret

import unittest

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        self.assertEqual(self.solution.canPartitionKSubsets([4, 3, 2, 3, 5, 2, 1], 4), True)


    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()

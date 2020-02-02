import unittest

import copy
class Solution(object):
    def findSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = set()
        current = []
        self.dfs(0, current, nums, ret)
        return [list(tup) for tup in ret]

    def dfs(self, index, current, nums, ret):
        nums_len = len(nums)
        if index >= nums_len:
            return
        prev = current[-1] if current else -99999
        if nums[index] >= prev:
            # select
            current.append(nums[index])
            len(current) >= 2 and ret.add(tuple(current))
            self.dfs(index+1, current, nums, ret)
            # not select
            current.pop()
            self.dfs(index+1, current, nums, ret)
        else:
            # not select
            self.dfs(index + 1, current, nums, ret)

    # def findNums(self, nums):
    #     lists = []
    #     for i in xrange(len(nums)):
    #         # print i
    #         if i == 0 or nums[i-1] > nums[i]:
    #             tmp = [nums[i]]
    #         else:
    #             continue
    #         for j in xrange(i + 1, len(nums)):
    #             if tmp[-1] <= nums[j]:
    #                 tmp.append(nums[j])
    #         if len(tmp) >= 2:
    #             lists.append(tmp)
    #     return lists
    #
    # def selectNum(self, nums, ret):
    #     for i in xrange(len(nums)):
    #         tmp = [nums[i]]
    #         self.mydfs(i+1, tmp, nums, ret)
    #
    # def mydfs(self, index, tmp, nums, ret):
    #     if index >= len(nums):
    #         return
    #     # select
    #     tmp.append(nums[index])
    #     if tmp not in ret:
    #         ret.append(copy.deepcopy(tmp))
    #     self.mydfs(index+1, tmp, nums, ret)
    #     tmp.pop()
    #     # not select
    #     self.mydfs(index+1, tmp, nums, ret)

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        print "ret:%s\n" % (self.solution.findSubsequences([4, 6, 7, 7, 3, 6, 5, 9]), )

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
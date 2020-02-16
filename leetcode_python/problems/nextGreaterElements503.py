import unittest


class Solution(object):
    # def nextGreaterElements(self, nums):
    #     """
    #     :type nums: List[int]
    #     :rtype: List[int]
    #     """
    #     ret = []
    #     nums_len = len(nums)
    #     for index, num in enumerate(nums):
    #         current = num
    #         added = False
    #         for index_1 in range(index + 1, index + nums_len):
    #             nex = nums[index_1 % nums_len]
    #             if current < nex:
    #                 ret.append(nex)
    #                 added = True
    #                 break
    #         if not added:
    #             ret.append(-1)
    #     return ret
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        stack = []
        nums_len = len(nums)
        ret = [-1] * nums_len
        for index in range(nums_len * 2):
            num = nums[index % nums_len]
            while len(stack) > 0 and nums[stack[-1]] < num:
                ret[stack[-1]] = num
                stack.pop(-1)
            index < nums_len and stack.append(index)
            # print "push num:%s, index:%s, stack:%s" % (num, index, stack)
        return ret



class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        # self.assertEqual(self.solution.nextGreaterElements([1,2,1]), [2,-1,2])
        self.assertEqual(self.solution.nextGreaterElements([1,2,3,4,3]), [2,3,4,-1,4])

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
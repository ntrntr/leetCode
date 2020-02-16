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
        new_nums = nums + nums[:-1]
        ret = [-1] * nums_len
        for index, num in enumerate(new_nums):
            while len(stack) > 0 and stack[-1][0] < num:
                if stack[-1][1] < nums_len:
                    ret[stack[-1][1]] = num
                # print "set index:%s to %s, ret:%s" % (stack[-1][-1], num, ret,)
                stack.pop(-1)
            stack.append((num, index,))
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
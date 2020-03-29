import unittest


class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret_dict = {0:0}
        count = 0
        ret = 0
        for index, num in enumerate(nums, 1):
            if num == 1:
                count += 1
            else:
                count -= 1
            if count in ret_dict:
                ret = max(ret, index - ret_dict[count])
            else:
                ret_dict[count] = index
        return ret



class MyTestCase(unittest.TestCase):

    def setUp(self):
        pass

    def test_something1(self):
        solution = Solution()

    def test_something2(self):
        solution = Solution()
        # ret = solution.findMaxLength([0,1])
        # self.assertEqual(ret, 2)
        # ret = solution.findMaxLength([0,1,0])
        # self.assertEqual(ret, 2)
        # ret = solution.findMaxLength([0,0,1,0,0,0,1,1])
        # self.assertEqual(ret, 6)
        ret = solution.findMaxLength([1,1,1,1,1,1,1,0,0,0,0,1,1,0,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,1,0,0,1,1,1,1,1,0,0,1,0,1,1,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,0,0,1,1,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,0,1,0,1,1])
        self.assertEqual(ret, 94)

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
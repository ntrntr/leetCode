import unittest


class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result_list = []
        zero_count = 0
        one_count = 0
        result_list.append((zero_count, one_count))
        for index,num in enumerate(nums):
            if num == 1:
                one_count += 1
            else:
                zero_count += 1
            result_list.append((one_count, zero_count))
        if zero_count == one_count:
            return zero_count * 2
        elif zero_count < one_count:
            return self.getMaxLength(result_list, zero_count * 2)
        else:
            return self.getMaxLength(result_list, one_count * 2)

    def getMaxLength(self, result_list, upper_bound):
        current_reuslt = 0
        list_len = len(result_list) - 1
        for i in xrange(list_len):
            for j in xrange(current_reuslt + 2, upper_bound + 1, 2):
                if i + j >= list_len + 1:
                    break
                if result_list[i + j][0] - result_list[i][0] == result_list[i + j][1] - result_list[i][1]:
                    current_reuslt = max(current_reuslt, j)
        return current_reuslt


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
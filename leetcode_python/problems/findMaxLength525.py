import unittest


class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        zero_count = []
        one_count = []
        for index,num in enumerate(nums):
            if num == 1:
                one_count.append(index)
            else:
                zero_count.append(index)
        if len(zero_count) == len(one_count):
            return len(zero_count) * 2
        elif len(zero_count) < len(one_count):
            return self.getMaxLength(0, len(zero_count) - 1,zero_count, len(zero_count) * 2)
        else:
            return self.getMaxLength(0, len(one_count) - 1, one_count, len(one_count) * 2)

    def getMaxLength(self, left_index, right_index, count_index, upper_len):
        if left_index > right_index:
            return 0
        if (count_index[right_index] - count_index[left_index] + 1)<= upper_len:
            return (right_index - left_index + 1) * 2
        else:
            return max(self.getMaxLength(left_index + 1, right_index, count_index, upper_len), self.getMaxLength(left_index, right_index-1, count_index, upper_len))

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
        ret = solution.findMaxLength([0,0,1,0,0,0,1,1])
        self.assertEqual(ret, 6)

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
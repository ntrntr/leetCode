import unittest


class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = []
        lens = len(nums)
        for i in xrange(lens):
            val = nums[i]
            nums[val % lens] = nums[val % lens] + lens
        for i in xrange(lens):
            if nums[i] >= 2 * lens:
                res.append(i)
        return res


class MyTestCase(unittest.TestCase):

    def setUp(self):
        pass

    def test_something1(self):
        solution = Solution()
        ret = [4,3,2,7,8,2,3,1]
        self.assertEqual([2,3], solution.findDuplicates(ret))

    def test_something2(self):
        solution = Solution()

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
import unittest


class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = []
        for x in nums:
            if nums[abs(x)-1] < 0:
                res.append(abs(x))
            else:
                nums[abs(x)-1] *= -1
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
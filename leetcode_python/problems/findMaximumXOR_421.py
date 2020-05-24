import unittest


class Solution(object):
    def findMaximumXOR1(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret = 0
        nums_len = len(nums)
        for i in range(nums_len):
            for j in range(nums_len):
                if i != j:
                    ret = max(ret, nums[i] ^ nums[j])
        return ret





class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        pass

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
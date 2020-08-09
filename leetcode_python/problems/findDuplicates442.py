import unittest


class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        my_dct = {}
        for num in nums:
            my_dct[num] = my_dct.get(num, 0) + 1
        return [k for k,v in my_dct.items() if v == 2]



class MyTestCase(unittest.TestCase):

    def setUp(self):
        pass

    def test_something1(self):
        solution = Solution()

    def test_something2(self):
        solution = Solution()

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
class Solution(object):

    

    def racecar(self, target):
        """
        :type target: int
        :rtype: int
        """


import unittest

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def tearDown(self):
        self.solution = None

    def test_something1(self):
        pass

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

if __name__ == '__main__':
    unittest.main()
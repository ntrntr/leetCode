import unittest


class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num < 0:
            return '-'+self.convertToBase7(-num)
        else:
            if num == 0:
                return str(0)
            ret = ''
            while num:
                v = num % 7
                num = num // 7
                ret = str(v) + ret
            return ret

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        self.assertEqual('202', self.solution.convertToBase7(100))
        self.assertEqual('-10', self.solution.convertToBase7(-7))


    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
import unittest
class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        ret = 0
        if num > 0:
            count = 0
            while num:
                tmp = num & 0x00000001
                bitValue = 0 if tmp == 1 else 1
                if bitValue:
                    ret = ret + (1 << count)
                count = count + 1
                num = num >> 1
        else:
            ret = ((1<<32)-1-num) & num
        return ret


class myTest(unittest.TestCase):

    def setUp(self):
        super(myTest, self).setUp()
        self.solution = Solution()

    def tearDown(self):
        super(myTest, self).tearDown()
        self.solution = None

    def test_1(self):
        self.assertEqual(self.solution.findComplement(5), 2)
        pass

    def test_2(self):
        self.assertEqual(self.solution.findComplement(1), 0)
        pass

    def test_3(self):
        self.assertEqual(self.solution.findComplement(-1), 0)
        pass


if __name__ == "__main__":
    unittest.main()
    pass

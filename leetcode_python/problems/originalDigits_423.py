import unittest
import copy

class Solution(object):
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        digits_num = [ "one", "two", "three", "four", "five", "six", "seven", "nine"]
        # digits_order = [('g', "eight", 8), ('u', )]
        digit_count = {}
        for i in range(ord('a'), ord('z')+1):
            digit_count[chr(i)] = 0

        tmp = copy.deepcopy(digit_count)
        for num in digits_num:
            for c in num:
                tmp[c] += 1

        for k,v in tmp.iteritems():
            if v:
                print "key:%s, value:%s" % (k, v)

        for i in range(ord('a'), ord('z')+1):
            digit_count[chr(i)] = 0
        # ord char to int, chr int to char
        for c in s:
            digit_count[c] += 1
        return ""



class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        self.assertEqual(self.solution.originalDigits("one"), "")

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
import unittest
import copy

class Solution(object):
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        digit_count = {}

        for ss in s:
            digit_count[ss] = 1 + digit_count.get(ss, 0)

        find_list = [
            ('z', 'zero', 0),
            ('x', 'six', 6),
            ('w', 'two', 2),
            ('u', 'four', 4),
            ('g', 'eight', 8),
            ('t', 'three', 3),
            ('s', 'seven', 7),
            ('o', 'one', 1),
            ('v', 'five', 5),
            ('i', 'nine', 9),
        ]

        ret = [0] * 10
        for c, d, v in find_list:
            dcount = digit_count.get(c, 0)
            if dcount > 0:
                ret[v] = dcount
                for dd in d:
                    digit_count[dd] -= dcount
        r = ""
        for index, v in enumerate(ret):
            if v:
                r += str(index) * v
        return r



class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        self.assertEqual(self.solution.originalDigits("one"), "1")

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
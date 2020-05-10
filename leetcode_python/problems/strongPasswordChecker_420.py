import unittest


class Solution(object):
    VALID_PASSWORD = 0
    LESS_PASSWORD = 1 << 0
    TOO_LONG_PASSWORD = 1 << 1
    MISS_ONE_LOWER_LETTER = 1 << 2
    MISS_ONE_UP_LETTER = 1 << 3
    MISS_ONE_DIGIT = 1 << 4
    SAME_DIGIT = 1 << 5


    def checkPassWorldValid(self, s):
        ret = self.VALID_PASSWORD
        if len(s) < 6:
            ret |= self.LESS_PASSWORD
        if len(s) > 20:
            ret |=  self.TOO_LONG_PASSWORD
        contains_lower = False
        contains_upper = False
        contains_digit = False
        for c in s:
            contains_lower = contains_lower or c.islower()
            contains_upper = contains_upper or c.isupper()
            contains_digit = contains_digit or c.isdigit()
        if not contains_lower:
            ret |= self.MISS_ONE_LOWER_LETTER
        if not contains_upper:
            ret |= self.MISS_ONE_UP_LETTER
        if not contains_digit:
            ret |= self.MISS_ONE_DIGIT

        for i in range(1, len(s)-1):
            if s[i-1] == s[i] and s[i] == s[i+1]:
                ret |= self.SAME_DIGIT

        return ret

    def strongPasswordChecker(self, s):
        """
        :type s: str
        :rtype: int
        """
        ret = self.checkPassWorldValid(s)
        if ret == self.VALID_PASSWORD:
            return 0
        else:
            return self.modifyCount(s, ret)

    def modifyCount(self, s, ret):
        if ret == self.LESS_PASSWORD:
            return 6 - len(s)
        elif ret == self.TOO_LONG_PASSWORD:
            return self.subString(s)

    def subString(self, s):
        for i in range(len(s)):
            pass



class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        ret = self.solution.strongPasswordChecker("Abcd1234")
        self.assertEqual(ret, 0)

    def test_something2(self):
        ret = self.solution.strongPasswordChecker("Abc")
        self.assertEqual(ret, 0)

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
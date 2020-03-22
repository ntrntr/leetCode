import unittest


class Solution(object):
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        ret = ''
        for dct in d:
            dct_len = len(dct)
            ret_len = len(ret)
            if dct_len < ret_len:
                continue
            if dct_len == ret_len and dct > ret:
                continue
            if self.isSub(s, dct):
                ret = dct
        return ret


    def isSub(self, long_str, sub_str):
        idx = 0
        long_str_len = len(long_str)
        sub_str_len = len(sub_str)
        for index, s in enumerate(long_str):
            if s == sub_str[idx]:
                idx = idx + 1
            if idx >= len(sub_str):
                return True
            if long_str_len - index - 1  < sub_str_len - idx:
                return False
        return False

class MyTestCase(unittest.TestCase):

    def setUp(self):
        pass

    def test_something1(self):
        solution = Solution()
        self.assertEqual(solution.findLongestWord("abpcplea", ["ale","apple","monkey","plea"]), "apple")

    def test_something2(self):
        solution = Solution()

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
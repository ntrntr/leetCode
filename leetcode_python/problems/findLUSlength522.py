import unittest
import functools

def mycmp(left, right):
    if right[0] == left[0]:
        if right[1]  == left[1]:
            return 0
        elif right[1]  > left[1]:
            return 1
        else:
            return -1
    return right[0] - left[0]

class Solution(object):
    def findLUSlength(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        my_dict = {}
        for str in strs:
            if not my_dict.has_key(str):
                my_dict[str] = 0
            my_dict[str] = my_dict[str] + 1
        my_data = [(len(k), k) for k, v in my_dict.iteritems() if v <= 1]
        my_data.sort(key=functools.cmp_to_key(mycmp))
        if my_data:
            for str_len, str in my_data:
                if self.checkValid(str, my_dict):
                    return str_len
            return -1
        else:
            return -1

    def checkValid(self, str, my_dict):
        len_str = len(str)
        candidates = [k for k,v in my_dict.iteritems() if len(k) >= len_str and k != str]
        for candi in candidates:
            if self.isSubsequence(str, candi):
                return False
        return True

    def isSubsequence(self, sub_str, str):
        str_len = len(str)
        index = 0
        for i in xrange(str_len):
            if str[i] == sub_str[index]:
                index = index + 1
                if index >= len(sub_str):
                    break
            else:
                continue
        if index == len(sub_str):
            return True
        return False





class MyTestCase(unittest.TestCase):

    def setUp(self):
        pass

    def test_something1(self):
        solution = Solution()
        # self.assertEqual(solution.findLUSlength(["aabbcc", "aabbcc","cb"]), 2)
        self.assertEqual(solution.findLUSlength(["aaa","aaa","aa"]), -1)
        # solution.findLUSlength(["aabbcc", "aabbcc", "cb"])

    def test_something2(self):
        solution = Solution()

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
import unittest

import copy
class Solution(object):
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        if k <= 1:
            return len(s)
        values = [{},]
        currentDic = {}
        for i, j in enumerate(s):
            currentDic[j] = currentDic.get(j, 0) + 1
            newDict = {}
            newDict.update(currentDic)
            values.append(newDict)
        # print values
        current_len = 0
        s_len = len(s)
        for i in xrange(s_len):
            for j in xrange(0, i):
                if i - j + 1 < current_len:
                    break
                # print "sub str:%s, valid:%s, to_idx:%s, from_idx:%s, current_len:%s" % (s[j:i+1], self.checkValid(j, i, values, k), i, j, current_len,)
                # print "todict:%s, from dict:%s" % (values[i + 1], values[j],)
                if self.checkValid(j, i, values, k):
                    current_len = max(current_len, i - j + 1)
                    # print 'set current_len', current_len
        return current_len

    def checkValid(self, from_idx, to_idx, values, min_len):
        to_dict = values[to_idx + 1]
        from_dict = values[from_idx]
        for k, v in to_dict.iteritems():
            target = from_dict.get(k, 0)
            if v - target != 0 and v - target < min_len:
                return False
        return True

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        # self.assertEqual(self.solution.longestSubstring('aaabb', 3), 3)
        self.assertEqual(self.solution.longestSubstring('ababbc', 2), 5)

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
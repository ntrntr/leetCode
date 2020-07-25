import unittest
import copy

class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        s_len = len(s)
        if s_len <= k + 1:
            return s_len
        ret = 1
        test = {}
        cache = [{}, ]
        for index, c in enumerate(s):
            test[c] = 1 + test.get(c, 0)
            cache.append(copy.deepcopy(test))
            while True:
                next_expect_len = ret + 1
                next_index = index + 1 - next_expect_len
                if next_index >= 0:
                    if self.checkValid(cache[next_index], cache[index+1], k):
                        ret = next_expect_len
                    else:
                        cache[next_index] = {}
                        break
                else:
                    break
        return ret

    def checkValid(self, start_dict, end_dict, kk):
        largetst_count = 0
        total_sum = 0
        for k, v in end_dict.iteritems():
            s_v = start_dict.get(k, 0)
            count = v - s_v
            total_sum += count
            largetst_count = max(largetst_count, count)
        left_not_same = total_sum - largetst_count
        return left_not_same <= kk



class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()


    def test_something1(self):
        # self.assertEqual(4, self.solution.characterReplacement("ABAB", 2))
        self.assertEqual(4, self.solution.characterReplacement("AABABBA", 1))

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
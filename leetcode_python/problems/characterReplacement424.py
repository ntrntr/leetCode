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
        unique_count = 0
        ret = 0
        start = 0
        count_array = [0] * 26
        for index, ch in enumerate(s):
            val = ord(ch) - ord('A')
            count_array[val] += 1
            unique_count = max(unique_count, count_array[val])
            if index - start + 1 - unique_count <= k:
                ret = max(ret, index - start + 1)
            else:
                char_val = ord(s[start]) - ord('A')
                count_array[char_val] -= 1
                start += 1

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
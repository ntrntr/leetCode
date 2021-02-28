import unittest


class Solution(object):
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        chars_len = len(chars)
        if chars_len <= 1:
            return chars_len
        ret = 0
        current = chars[0]
        count = 1
        index = 1
        modify_index = 0
        while index < chars_len:
            if chars[index] == current:
                count = count + 1
            elif chars[index] != current:
                ret = ret + 1 + (len(str(count)) if count > 1 else 0)
                chars[modify_index] = current
                modify_index = modify_index + 1
                if count > 1:
                    for c in str(count):
                        chars[modify_index] = c
                        modify_index = modify_index + 1
                current = chars[index]
                count = 1
            index = index + 1
        ret = ret + 1 + (len(str(count)) if count > 1 else 0)
        chars[modify_index] = current
        modify_index = modify_index + 1
        if count > 1:
            for c in str(count):
                chars[modify_index] = c
                modify_index = modify_index + 1
        return ret


class MyTestCase(unittest.TestCase):

    def setUp(self):

        self.solution = Solution()
        # cc = ["a","a","a","b","b","a","a"]
        # self.assertEqual(self.solution.compress(cc), 6)

    def test_something1(self):

        self.solution = Solution()
        # cc = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
        # self.assertEqual(self.solution.compress(cc), 4)

    def test_something2(self):
        self.solution = Solution()
        cc = ["a", "b", "c"]
        self.assertEqual(self.solution.compress(cc), 3)

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
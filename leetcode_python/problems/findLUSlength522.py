import unittest


class Solution(object):
    def findLUSlength(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        candidate = []
        max_len = 0
        for str in strs:
            if len(str) > max_len:
                max_len = len(str)
                candidate = []
                candidate.append(str)
            elif len(str) == max_len:
                candidate.append(str)
        if len(candidate) == 1:
            return len(candidate[0])
        else:
            my_dict = {}
            for str in candidate:
                if str in my_dict:
                    my_dict[str] = my_dict[str] + 1
                else:
                    my_dict[str] = 1
            if len(my_dict.keys()) == 1:
                return -1
            else:
                for k,v in my_dict.iteritems():
                    if v == 1:
                        return len(k)
                return -1

class MyTestCase(unittest.TestCase):

    def setUp(self):
        pass

    def test_something1(self):
        solution = Solution()
        self.assertEqual(solution.findLUSlength(["aabbcc", "aabbcc","cb"]), 2)

    def test_something2(self):
        solution = Solution()

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
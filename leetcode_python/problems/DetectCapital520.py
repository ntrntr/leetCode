import unittest


class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        if word == word.upper() or word == word.lower() or (word[0].isupper() and word[1:] == word[1:].lower()):
            return True
        return False


import unittest

class MyTestCase(unittest.TestCase):

    def setUp(self):
        pass

    def test_something1(self):
        solution = Solution()
        self.assertEqual(solution.detectCapitalUse("USA"), True)
        self.assertEqual(solution.detectCapitalUse("Usa"), True)
        self.assertEqual(solution.detectCapitalUse("leetcode"), True)
        self.assertEqual(solution.detectCapitalUse("Google"), True)

    def test_something2(self):
        solution = Solution()

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
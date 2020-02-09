import unittest


class Solution(object):
    fib_cache = {0:0, 1:1}
    def fib(self, N):
        """
        :type N: int
        :rtype: int
        """
        if self.fib_cache.get(N, None) is not None:
            return self.fib_cache[N]
        self.fib_cache[N-1] = self.fib(N-1)
        self.fib_cache[N-2] = self.fib(N-2)
        self.fib_cache[N] = self.fib_cache[N-1] + self.fib_cache[N-2]
        return self.fib_cache[N]

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        self.assertEqual(1, self.solution.fib(2))
        self.assertEqual(2, self.solution.fib(3))
        self.assertEqual(3, self.solution.fib(4))

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
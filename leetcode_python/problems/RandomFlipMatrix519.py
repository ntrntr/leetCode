import unittest


class Solution(object):

    def __init__(self, n_rows, n_cols):
        """
        :type n_rows: int
        :type n_cols: int
        """
        self.n_rows = n_rows
        self.n_cols = n_cols
        self.data = []
        for i in range(self.n_rows):
            for j in range(self.n_cols):
                self.data.append([i, j])
        self.reset()

    def flip(self):
        """
        :rtype: List[int]
        """
        return self.data[self.index.pop()]

    def reset(self):
        """
        :rtype: None
        """
        self.index = [i for i in range(self.n_rows * self.n_cols)]

        import random
        random.shuffle(self.index)


# Your Solution object will be instantiated and called as such:
# obj = Solution(n_rows, n_cols)
# param_1 = obj.flip()
# obj.reset()

class MyTestCase(unittest.TestCase):

    def setUp(self):
        # self.solution = Solution()
        pass

    def test_something1(self):
        cls = Solution(2,2)
        print cls.flip()
        print cls.flip()
        print cls.flip()
        print cls.flip()

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        # self.solution = [i for i in range()]
        pass

if __name__ == '__main__':
    unittest.main()
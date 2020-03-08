import unittest

import random
class Solution(object):

    def __init__(self, n_rows, n_cols):
        """
        :type n_rows: int
        :type n_cols: int
        """
        self.n_rows = n_rows
        self.n_cols = n_cols
        self.data = []
        if not self.useNewStrategy():
            self.index = [i for i in xrange(self.n_rows * self.n_cols)]
            random.shuffle(self.index)
        else:
            self.index_contians = {}
        self.reset()

    def flip(self):
        """
        :rtype: List[int]
        """
        if not self.useNewStrategy():
            index = self.current_index
            self.current_index = (self.current_index + 1) % (self.n_rows * self.n_cols)
        else:
            index = self.current_index
            self.index_contians[index] = True
            new_index = random.randint(0, self.n_rows * self.n_cols - 1)
            while new_index in self.index_contians:
                new_index = random.randint(0, self.n_rows * self.n_cols - 1)
            self.current_index = new_index
        return [index // self.n_cols, index % self.n_cols]


    def reset(self):
        """
        :rtype: None
        """
        if not self.useNewStrategy():
            self.current_index = random.randint(0, self.n_rows * self.n_cols - 1)
        else:
            self.index_contians = {}
            self.current_index = random.randint(0, self.n_rows * self.n_cols - 1)


    def useNewStrategy(self):
        return self.n_rows * self.n_cols > 1500


# Your Solution object will be instantiated and called as such:
# obj = Solution(n_rows, n_cols)
# param_1 = obj.flip()
# obj.reset()

class MyTestCase(unittest.TestCase):

    def setUp(self):
        # self.solution = Solution()
        pass

    def test_something1(self):
        cls = Solution(1, 2)
        print cls.flip()
        print cls.flip()
        # print cls.flip()
        # print cls.flip()

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        # self.solution = [i for i in range()]
        pass

if __name__ == '__main__':
    unittest.main()
import functools
def mycmp(left, right):
    if left[0] == right[0]:
        return right[1] - left[1]
    else:
        return left[0] - right[0]

class Solution(object):
    def findMaximizedCapital(self, k, W, Profits, Capital):
        """
        :type k: int
        :type W: int
        :type Profits: List[int]
        :type Capital: List[int]
        :rtype: int
        """
        if k==0:
            return W
        import collections
        my_dict = {}

        tm = zip(Capital, Profits)
        self.remove_and_update(tm, my_dict, W)
        currentW = W
        while k>0 and my_dict:
            max_key = max(my_dict.keys())
            my_dict[max_key] = my_dict[max_key] - 1
            if my_dict[max_key] == 0:
                my_dict.pop(max_key)
            # print "add", max_key
            currentW = max_key + currentW
            self.remove_and_update(tm, my_dict, currentW)
            k = k -1
        # print "ret", currentW
        return currentW


    def remove_and_update(self, values, my_dict, current_w):

        var_to_remove = []
        for var in values:
            if var[0] <= current_w:
                if var[1] in my_dict:
                    my_dict[var[1]] = my_dict[var[1]] + 1
                else:
                    my_dict[var[1]] = 1
                var_to_remove.append(var)
        for var in var_to_remove:
            values.remove(var)


import unittest

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        ret = self.solution.findMaximizedCapital(2,0, [1,2,3], [0,1,1])

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
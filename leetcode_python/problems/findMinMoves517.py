import unittest

# First we check the sum of dresses in all machines. if that number cannot be divided by count of machines, there is no solution.
#
# Otherwise, we can always transfer a dress from one machine to another, one at a time until every machines reach the same number, so there must be a solution. In this way, the total actions is sum of operations on every machine.
#
# Since we can operate several machines at the same time, the minium number of moves is the maximum number of necessary operations on every machine.
#
# For a single machine, necessary operations is to transfer dresses from one side to another until sum of both sides and itself reaches the average number. We can calculate (required dresses) - (contained dresses) of each side as L and R:
#
# L > 0 && R > 0: both sides lacks dresses, and we can only export one dress from current machines at a time, so result is abs(L) + abs(R)
# L < 0 && R < 0: both sides contains too many dresses, and we can import dresses from both sides at the same time, so result is max(abs(L), abs(R))
# L < 0 && R > 0 or L >0 && R < 0: the side with a larger absolute value will import/export its extra dresses from/to current machine or other side, so result is max(abs(L), abs(R))
#
# For example, [1, 0, 5], average is 2
# for 1, L = 0 * 2 - 0 = 0, R = 2 * 2 - 5= -1, result = 1
# for 0, L = 1 * 2 - 1= 1, R = 1 * 2 - 5 = -3, result = 3
# for 5, L = 2 * 2 - 1= 3, R = 0 * 2 - 0= 0, result = 3
# so minium moves is 3
# from https://leetcode.com/problems/super-washing-machines/discuss/99181/C%2B%2B-16ms-O(n)-solution-(with-trivial-proof)

class Solution(object):
    def findMinMoves(self, machines):
        """
        :type machines: List[int]
        :rtype: int
        """
        machines_sums = 0
        for n in machines:
            machines_sums += n
        machines_len = len(machines)
        if machines_sums % machines_len != 0:
            return -1
        expect_num = machines_sums / machines_len
        left_sum = []
        sum = 0
        for num in machines:
            sum += num
            left_sum.append(sum)
        ret = 0
        for index in range(machines_len):
            if index - 1 < 0:
                L = 0
            else:
                L = expect_num * index - left_sum[index - 1]

            if index + 1 >= machines_len:
                R = 0
            else:
                R = expect_num * (machines_len - index - 1) - (left_sum[machines_len - 1] - left_sum[index])

            if L > 0 and R > 0:
                tmp = self.myabs(L) + self.myabs(R)
                ret = max(tmp, ret)
            else:
                tmp = max(self.myabs(L), self.myabs(R))
                ret = max(tmp, ret)
        return ret

    def myabs(self, n):
        if n >= 0:
            return n
        else:
            return -n



class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        self.assertEqual(self.solution.findMinMoves([1,0,5]),3)

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
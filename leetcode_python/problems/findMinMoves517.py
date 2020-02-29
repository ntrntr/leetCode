import unittest


class Solution(object):
    def findMinMoves(self, machines):
        """
        :type machines: List[int]
        :rtype: int
        """
        machines_sums = sum(machines)
        machines_len = len(machines)
        if machines_sums % machines_len != 0:
            return -1
        ret = 0
        expected_num = machines_sums // machines_len
        for i in range(machines_len):
            if machines[i] == expected_num:
                continue
            elif machines[i] < expected_num:
                require = expected_num - machines[i]
            else:
                push = machines[i]



class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        pass

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
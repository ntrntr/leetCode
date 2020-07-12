import unittest
import copy

class Solution(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        tmp_dict = {}
        tmp_dict[1] = [[1]]
        tmp_dict[2] = [[1, 2], [2, 1]]
        if N <= 2:
            return len(tmp_dict[N])
        count = 3
        while count <= N:
            prev_data = tmp_dict[count-1]
            next_data = copy.deepcopy(prev_data)
            for item in next_data:
                item.append(count)
            for data_item in prev_data:
                for i in range(1, count, 1):
                    if self._check_valid(data_item[i-1], count) and self._check_valid(count, i):
                        new_data = copy.deepcopy(data_item)
                        new_data.append(data_item[i-1])
                        new_data[i-1] = count
                        next_data.append(new_data)
            tmp_dict[count] = next_data
            count = count + 1
        return len(tmp_dict[N])

    def _check_valid(self, value, index):
        if value >= index and value % index == 0:
            return True
        if value <= index and index % value == 0:
            return True
        return False


class MyTestCase(unittest.TestCase):

    def setUp(self):
        pass

    def test_something1(self):
        solution = Solution()
        self.assertEqual(solution.countArrangement(1), 1)
        self.assertEqual(solution.countArrangement(2), 2)
        # self.assertEqual(solution.countArrangement(6), 36)
        # self.assertEqual(solution.countArrangement(6), 36)
        self.assertEqual(solution.countArrangement(6), 36)

    def test_something2(self):
        solution = Solution()

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
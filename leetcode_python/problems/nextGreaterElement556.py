import unittest


class Solution(object):
    def nextGreaterElement(self, n):
        """
        :type n: int
        :rtype: int
        """
        n_str = str(n)
        if ''.join(sorted(n_str, reverse=True)) == n_str:
            return -1
        n_len = len(n_str)
        cur = n_str[-1]
        str_array = [b for b in n_str]
        for i in reversed(range(n_len - 1)):
            if cur > n_str[i]:
                break
            else:
                cur = n_str[i]
        cur_index = i
        swap_index = i + 1
        swap_value = str_array[swap_index]
        for i in range(cur_index + 1, n_len):
            if str_array[cur_index] < str_array[i] and swap_value > str_array[i]:
                swap_value = str_array[i]
                swap_index = i
        tmp = str_array[cur_index]
        str_array[cur_index] = str_array[swap_index]
        str_array[swap_index] = tmp
        tmp = sorted(str_array[cur_index+1:])
        final = str_array[0:cur_index+1] + tmp
        ret = int(''.join(final))
        if ret >= 0x7FFFFFFF:
            return -1
        else:
            return ret





class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        # self.assertEqual(self.solution.nextGreaterElement(12), 21)
        # self.assertEqual(self.solution.nextGreaterElement(21), -1)
        self.assertEqual(self.solution.nextGreaterElement(12443322), 13222344)
        self.assertEqual(self.solution.nextGreaterElement(1999999999), -1)


    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
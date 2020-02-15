import unittest


class Solution(object):
    def nextGreaterElement2(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        ret = []
        my_dict = {}
        for index, num in enumerate(nums2):
            my_dict[num] = index
        for num in nums1:
            index = my_dict[num] + 1
            isFind = False
            for ind in range(index, len(nums2)):
                if num < nums2[ind]:
                    ret.append(nums2[ind])
                    isFind = True
                    break
            if not isFind:
                ret.append(-1)
        return ret

    def nextGreaterElement1(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        my_stack = []
        nums2_len = len(nums2)
        quick_table = [-1] * nums2_len
        for index in range(nums2_len - 1, -1, -1):
            current_val = nums2[index]
            for idx in range(index + 1, nums2_len):
                new_val = nums2[idx]
                if current_val < new_val:
                    quick_table[index] = new_val
                    break
                else:
                    # current_val >= new val
                    if quick_table[idx] == -1:
                        break
                    elif quick_table[idx] > current_val:
                        quick_table[index] = quick_table[idx]
                        break
        print 'quick_table', quick_table
        my_dict = {}
        for index, num in enumerate(nums2):
            my_dict[num] = index
        return [quick_table[my_dict[num]] for num in nums1]

    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        stack = []
        ret_dict = {}
        for num in nums2:
            while len(stack) > 0 and stack[-1] < num:
                ret_dict[stack[-1]] = num
                stack.pop(-1)
            stack.append(num)
        # print "stack", ret_dict
        return [ret_dict.get(num, -1) for num in nums1]

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        # self.assertEqual(self.solution.nextGreaterElement([2,4], [1,2,3,4]), [3, -1])
        # self.assertEqual(self.solution.nextGreaterElement(nums1 = [4,1,2], nums2 = [1,3,4,2]), [-1,3,-1])
        self.assertEqual(self.solution.nextGreaterElement(nums1 = [1, 3, 5, 2, 4], nums2 = [6, 5, 4, 3, 2, 1, 7]), [7,7,7,7,7])



    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
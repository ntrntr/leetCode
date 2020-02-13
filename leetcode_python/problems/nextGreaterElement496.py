import unittest


class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
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

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        self.assertEqual(self.solution.nextGreaterElement([2,4], [1,2,3,4]), [3, -1])
        self.assertEqual(self.solution.nextGreaterElement(nums1 = [4,1,2], nums2 = [1,3,4,2]), [-1,3,-1])

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
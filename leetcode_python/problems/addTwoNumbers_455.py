import unittest


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l1_num = []
        l2_num = []
        helper = l1
        while helper:
            l1_num.append(helper.value)
            helper = helper.next
        helper = l2
        while helper:
            l2_num.append(helper.value)
            helper = helper.next
        if len(l1_num) < len(l2_num):
            tmp = l1
            l1 = l2
            l2 = tmp
            tmp = l1_num
            l1_num = l2_num
            l2_num = tmp
        upper = 0
        for index, val in enumerate(reversed(l2)):



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
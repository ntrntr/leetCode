import unittest

"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child

class Solution(object):
    def flatten(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        helper = Node(-1, None, None, None)
        self._faltten(head, helper)
        new_ret = helper.next
        if new_ret:
            new_ret.prev = None
        return new_ret

    def _faltten(self, head, helper):
        if not head:
            return helper
        item = head
        while item:
            new_node = Node(item.val, helper, None, None)
            helper.next = new_node
            if item.child:
                new_node = self._faltten(item.child, new_node)
            helper = new_node
            item = item.next
        return helper


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
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
            tmp_next = item.next
            new_node = item
            helper.next = new_node
            new_node.prev = helper
            new_node.next = None
            tmp_child = new_node.child
            new_node.child = None
            if tmp_child:
                new_node = self._faltten(tmp_child, new_node)
            helper = new_node
            item = tmp_next
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
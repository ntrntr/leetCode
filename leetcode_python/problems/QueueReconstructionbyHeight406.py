import unittest
import functools
def mycmp(left, right):
    if left[0] == right[0]:
        return left[1] - right[1]
    return -left[0] + right[0]
class Solution(object):
    # def reconstructQueue(self, people):
    #     """
    #     :type people: List[List[int]]
    #     :rtype: List[List[int]]
    #     """
    #     people.sort(key=functools.cmp_to_key(mycmp))
    #     listlen = len(people)
    #     ret = [None for i in xrange(listlen)]
    #     minIndex = 0
    #     for i in xrange(listlen):
    #         hight, index = people[i]
    #         largerCount = 0
    #         for j in xrange(0, index):
    #             if ret[j] is None or ret[j][0] >= hight:
    #                 largerCount = largerCount + 1
    #         if ret[index] is None and largerCount == index:
    #             ret[index] = people[i]
    #             continue
    #         else:
    #             # find next index
    #             for j in xrange(index, listlen):
    #                 if ret[j] is None and largerCount == index:
    #                     ret[j] = people[i]
    #                     break
    #                 else:
    #                     if ret[j]:
    #                         largerCount = largerCount + 1 if ret[j][0]>= hight else 0
    #                     else:
    #                         largerCount += 1
    #     return ret
    # def reconstructQueue(self, people):
    #     """
    #     :type people: List[List[int]]
    #     :rtype: List[List[int]]
    #     """
    #     zeros = sorted([x for x in people if x[1] == 0], key=lambda y: (y[0],))
    #     remains = sorted([x for x in people if x[1] != 0], key=lambda y: (-y[0],y[1]))
    #     ret = zeros
    #     for x in remains:
    #         cnt = 0
    #         for i in range(len(ret)):
    #             if ret[i][0] >= x[0]:
    #                 cnt+=1
    #             if cnt == x[1]:
    #                 ret.insert(i+1, x)
    #                 break
    #     return ret
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        people.sort(key=functools.cmp_to_key(mycmp))
        ret = []
        for p in people:
            ret.insert(p[1],p)
        return ret

import unittest

class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(True, True)

    def setUp(self):
        self.s = Solution()

    def test_1(self):
        a = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
        self.assertEqual(self.s.reconstructQueue(a), [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]])

if __name__ == '__main__':
    unittest.main()

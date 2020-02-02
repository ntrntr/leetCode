import random
import math

class Solution(object):

    def __init__(self, radius, x_center, y_center):
        """
        :type radius: float
        :type x_center: float
        :type y_center: float
        """
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center

    def randPoint(self):
        """
        :rtype: List[float]
        """
        x_offset, y_offset = self.randomOffset()
        return [x_offset + self.x_center, y_offset + self.y_center]

    def randomOffset(self):
        theta = random.uniform(0, 2 * math.pi)
        r = math.sqrt(random.uniform(0, self.radius))
        return r * math.cos(theta), r * math.sin(theta)

# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()

import unittest

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def tearDown(self):
        self.solution = None

    def test_something1(self):
        pass

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

if __name__ == '__main__':
    unittest.main()
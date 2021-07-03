import unittest


class Solution(object):
    def makesquare(self, matchsticks):
        """
        :type matchsticks: List[int]
        :rtype: bool
        """
        s = sum(matchsticks)
        if s % 4 != 0:
            return False
        expect_len = s / 4
        print 'expect len', expect_len
        four_len = [0l, 0l, 0l, 0l]
        return self.judge(four_len, 0, matchsticks, expect_len)

    def judge(self, four_len, index, matchsticks, expect_len):
        if index >= len(matchsticks):
            if four_len[0] == expect_len and four_len[1] == expect_len and four_len[2] == expect_len and four_len[
                3] == expect_len:
                return True
            else:
                return False

        for ii in xrange(4):
            if four_len[ii] + matchsticks[index] > expect_len:
                # can not add
                pass
            else:
                four_len[ii] = four_len[ii] + matchsticks[index]
                print index+1, four_len
                ret = self.judge(four_len, index + 1, matchsticks, expect_len)
                four_len[ii] = four_len[ii] - matchsticks[index]
                if ret:
                    return True
        return False


class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        ret = self.solution.makesquare([1569462,2402351,9513693,2220521,7730020,7930469,1040519,5767807,876240,350944,4674663,4809943,8379742,3517287,8034755])
        print ret

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
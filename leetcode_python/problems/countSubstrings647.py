import unittest


class Solution1(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        s_len = len(s)
        ret = 0
        dp = [[False] * s_len for i in range(s_len) ]
        for i in range(s_len-1,-1,-1):
            for j in range(i, s_len):
                dp[i][j] = s[i] == s[j] and (j - i < 3 or dp[i + 1][j - 1])
                if dp[i][j]:
                    ret += 1
        return ret

class Solution2(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        s_len = len(s)
        ret = 0
        for m in range(s_len):
            for j in range(m, s_len):
                if s[m:j+1] == s[m:j+1][::-1]:
                    ret += 1
        return ret

class Solution3:
    def countSubstrings(self, s):
	    L, r = len(s), 0
	    for i in range(L):
	    	for a,b in [(i,i),(i,i+1)]:
	    		while a >= 0 and b < L and s[a] == s[b]: a -= 1; b += 1
	    		r += (b-a)//2
	    return r

class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = 0
        T = ['@', '#']
        for ch in s:
            T.append(ch)
            T.append('#')
        T.append('$')
        print T
        P = [0] * len(T)
        C = R = 0
        for i in range(1, len(T) - 1):
            if i < R:
                P[i] = min(P[2 * C - i], R - i)
            while T[i + P[i] + 1] == T[i - P[i] - 1]:
                P[i] += 1

            if i + P[i] > R:
                R = i + P[i]
                C = i

            cnt += (P[i] + 1) // 2

        return cnt

class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        self.assertEqual(3, self.solution.countSubstrings("abc"))
        self.assertEqual(6, self.solution.countSubstrings("aaa"))


    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
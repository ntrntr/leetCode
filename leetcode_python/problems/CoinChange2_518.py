import unittest


class Solution(object):
    def change(self, amount, coins):
        """
        :type amount: int
        :type coins: List[int]
        :rtype: int
        """
        dp = [0 for i in xrange(amount+1)]
        dp[0] = 1
        coins.sort()
        for coin in coins:
            for i in range(coin, amount + 1, 1):
                dp[i] = dp[i - coin] + dp[i]
        return dp[amount]


# class Solution(object):
#     def change(self, amount, coins):
#         """
#         :type amount: int
#         :type coins: List[int]
#         :rtype: int
#         """
#         coins.sort()
#         while coins and coins[-1] > amount:
#             coins.pop()
#         coin_index = len(coins) - 1
#         return self.dfs(coin_index, amount, coins)
#
#     def dfs(self, coin_index, amount, coins):
#         ret = 0
#         if amount == 0:
#             return 1
#         if coin_index < 0:
#             return 0
#         if amount < 0:
#             return 0
#         current_value = coins[coin_index]
#         # use value
#         ret += self.dfs(coin_index, amount - current_value, coins)
#         # not use value
#         ret += self.dfs(coin_index - 1, amount, coins)
#         return ret


class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        self.assertEqual(self.solution.change(5, [1,2,5]), 4)
        self.assertEqual(self.solution.change(3, [2]), 0)
        self.assertEqual(self.solution.change(10, [10]), 1)

    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()
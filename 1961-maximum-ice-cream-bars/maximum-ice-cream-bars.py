class Solution(object):
    def maxIceCream(self, costs, coins):
        """
        :type costs: List[int]
        :type coins: int
        :rtype: int
        """

        costs.sort()
        cnt = 0
        n = len(costs)
        for i in range(n):
            if(coins- costs[i] >= 0):
                cnt += 1
                coins -= costs[i]
        return cnt
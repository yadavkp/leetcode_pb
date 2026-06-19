class Solution(object):
    def largestAltitude(self, gain):
        """
        :type gain: List[int]
        :rtype: int
        """

        arr = []
        n = len(gain)
        arr.append(0)
        mx = 0
        for i in range(n):
            arr.append(arr[i] + gain[i])
            mx = max(mx, arr[i+1])
        
        return mx

        
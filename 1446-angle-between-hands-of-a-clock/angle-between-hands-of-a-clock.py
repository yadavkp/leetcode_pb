class Solution(object):
    def angleClock(self, hour, minutes):
        """
        :type hour: int
        :type minutes: int
        :rtype: float
        """
        if(hour==12):
            hour = 0
        min_angle = minutes* 6.0
        hr_angle = hour * 30 + (minutes * 0.5)

        angle_diff = abs(min_angle - hr_angle)

        return min(angle_diff, 360- angle_diff)

        
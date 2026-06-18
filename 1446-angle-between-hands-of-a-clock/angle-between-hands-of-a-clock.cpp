class Solution {
public:
    double angleClock(int hour, int minutes) {
        
           
        if(hour == 12)hour = 0;

           // Minute hand: moves 6 degrees per minute (360 / 60)

        double min_angle = minutes * 6.0;
           
         // Hour hand:
        // 30 degrees per hour (360 / 12)
        // plus 0.5 degrees per minute (30 / 60

        double hr_angle =  hour * 30.0 + (minutes * 0.5);

        double angle_diff = abs(min_angle - hr_angle);

        // Return the smaller angle between the two possibilities

        return min ( angle_diff, 360 - angle_diff);

    }
};
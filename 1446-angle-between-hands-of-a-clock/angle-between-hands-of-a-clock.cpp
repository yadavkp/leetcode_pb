class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double angle_made_y_min_hand  = minutes*6.0;

        double angle_made_y_hr_hand = (hour==12) ? 0 : hour * 30.0;

        double now_angle_made_y_hr_hand_min = (minutes * 1.0 )/ 2.0;

        double x = angle_made_y_min_hand ;
        double y = angle_made_y_hr_hand;
        double z = now_angle_made_y_hr_hand_min;

            double pos_x = abs( x - (y + z));
            double pos_y = abs(360 - pos_x);
    return  (min ( pos_x, pos_y));

    }
};
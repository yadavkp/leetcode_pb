class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        
        
        sort(sides.begin(),sides.end());
        
        int a = sides[0],b = sides[1],c = sides[2];
        if(sides[0] + sides[1] > sides[2]){
            vector<double> ans(3,0.0);
            double ca = (b*b + c*c - a*a) /( 2.0 *b * c);

            double cb = ( a*a+ c*c - b*b) / (2.0 *a * c);

            double cc = (b*b + a*a - c*c) / (2.0 *b * a); // this values in the dimensionless //

            ans[0] = acos(ca) * (180.0 / M_PI); // apply acos// convert in the radian // for pi use in cpp ,, M_PI
            ans[1] = acos(cb) * (180.0 / M_PI);
            ans[2] = acos(cc) * (180.0 / M_PI);

            return ans;

        }

        return {};


    }
};
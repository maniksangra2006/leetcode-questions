class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
          vector<int>tri=sides; 
        sort(tri.begin(),tri.end()); 
        double a=tri[0];
        double b=tri[1];
        double c=tri[2]; 
        if(a+b<=c){
            return {};
        } 
        double angleA=acos((b*b+c*c-a*a)/(2.0*b*c))*180.0/M_PI;
        double angleB=acos((a*a+c*c-b*b)/(2.0*a*c))*180.0/M_PI;
        double angleC=acos((a*a+b*b-c*c)/(2.0*a*b))*180.0/M_PI;
        vector<double>ans={angleA,angleB,angleC}; 
        sort(ans.begin(),ans.end());
        return ans;
    }
};
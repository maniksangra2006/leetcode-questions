class Solution {
public:
    string str="Red";
    string trafficSignal(int timer) {
        if(timer==0) return "Green";
          if(timer==30) return "Orange";
          if(timer>1 && timer<30) return "Invalid";
          if(timer>30 && timer<=90) return "Red";
     return "Invalid";
    }
};
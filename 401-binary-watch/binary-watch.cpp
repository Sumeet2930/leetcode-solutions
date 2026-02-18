class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        
        for(int hour = 0; hour < 12; hour++) {
            for(int minute = 0; minute < 60; minute++) {
                
                // Count total set bits in hour and minute
                if(__builtin_popcount(hour) + __builtin_popcount(minute) == turnedOn) {
                    
                    // Format minute with leading zero if needed
                    string time = to_string(hour) + ":";
                    
                    if(minute < 10) 
                        time += "0";
                    
                    time += to_string(minute);
                    
                    result.push_back(time);
                }
            }
        }
        
        return result;
    }
};
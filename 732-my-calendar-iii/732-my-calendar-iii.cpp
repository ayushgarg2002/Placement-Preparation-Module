class MyCalendarThree {
public:
    int intervals[401][2]; // optimized for constraints -- up to 401 intervals with [i][0] being the start and [i][1] beind the end point
    unordered_map<int, int> um; // unordered map to maintain key-value pairs
    int highest = 0; // maintain highest k booking
    int pos = 0; // optimization so we don't have to iterate through 400 positions every time
    
    int book(int start, int end) {
        end--; // problem uses open intervals so don't include end
        intervals[pos][0] = start;
        intervals[pos][1] = end;
        pos++;
        
        for(auto i : um){ // for each start and end point, check if they would pass through the interval we are booking; if they do, ++
            if(i.first >= start && i.first <= end){
                um[i.first]++; // it passes through
                highest = max(highest, um[i.first]);
            }
        }
        if(um.find(start) == um.end()){ // if our start point hasnt been added yet, go through all previous intervals and see which ones it intersects
            for(int i = 0; i < pos; i++) if(start >= intervals[i][0] && start <= intervals[i][1]){
                um[start]++; // it passes through
                highest = max(highest, um[start]);
            }
        }
        if(um.find(end) == um.end()){ // if our end point hasnt been added yet, go through all previous intervals and see which ones it intersects
            for(int i = 0; i < pos; i++) if(end >= intervals[i][0] && end <= intervals[i][1]){
                um[end]++; // it passes through
                highest = max(highest, um[end]);
            }
        }
        return highest;
    }
};
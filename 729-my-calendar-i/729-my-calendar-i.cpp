class MyCalendar {
public:
    map<int, int> mapi;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto itr = mapi.upper_bound(start);
        if(itr ==mapi.end() || end<= itr->second)
        {
            mapi[end] = start;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
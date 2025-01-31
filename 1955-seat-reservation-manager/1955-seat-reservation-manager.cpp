class SeatManager {
public:
    int count;
    set<int> seats;
    SeatManager(int n) {
        count=1;

    }
    
    int reserve() {
        if(!seats.empty()){
            int seatNumber=*seats.begin();
            seats.erase(seats.begin());
            return seatNumber;
        }
        int seatNumber=count;
        count++;
        return seatNumber;
    }
    
    void unreserve(int seatNumber) {
       seats.insert(seatNumber);
        
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
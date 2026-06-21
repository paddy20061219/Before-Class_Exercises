#include <iostream>
#include <set>
using namespace std;

// LeetCode 1845 - Seat Reservation Manager
// AC version

class SeatManager {
private:
    set<int> availableSeats;

public:
    SeatManager(int n) {
        for(int i = 1; i <= n; i++){
            availableSeats.insert(i);
        }
    }

    int reserve() {
        int seat = *availableSeats.begin();

        availableSeats.erase(seat);

        return seat;
    }

    void unreserve(int seatNumber) {
        availableSeats.insert(seatNumber);
    }
};

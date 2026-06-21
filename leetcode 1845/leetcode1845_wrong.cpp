#include <iostream>
using namespace std;

// LeetCode 1845 - Seat Reservation Manager
// wrong version: this code is intentionally very wrong.

class SeatManager {
public:
    SeatManager(int n) {
        // 蠢錯誤：完全沒有記錄有哪些座位可以用
    }

    int reserve() {
        // 蠢錯誤：每次都回傳 1
        // 但同一個座位不能一直被重複預約。
        return 1;
    }

    void unreserve(int seatNumber) {
        // 蠢錯誤：取消預約也什麼都不做
    }
};

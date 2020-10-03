#include <bits/stdc++.h>
using namespace std;
class ParkingSystem {
   public:
    int arr[4];
    ParkingSystem(int big, int medium, int small) {
        arr[1] = big;
        arr[2] = medium;
        arr[3] = small;
    }

    bool addCar(int carType) {
        if (arr[carType] > 0) {
            arr[carType]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
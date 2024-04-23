class ParkingSystem {
    int* arr;

public:
    ParkingSystem(int big, int medium, int small) {
        arr = new int[3];
        arr[0] = big;
        arr[1] = medium;
        arr[2] = small;
    }

    bool addCar(int carType) {
        if (carType == 1) {
            if (arr[0] == 0)
                return false;
            arr[0] = arr[0] - 1;
            return true;
        }
        if (carType == 2) {

            if (arr[1] == 0)
                return false;
            arr[1] = arr[1] - 1;
            return true;
        }
        if (carType == 3) {

            if (arr[2] == 0)
                return false;
            arr[2] = arr[2] - 1;
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